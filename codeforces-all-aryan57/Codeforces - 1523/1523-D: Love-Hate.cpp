//https://codeforces.com/contest/1523/problem/D

/*
    author : aryan57
    created : 03-June-2021 14:43:04 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

mt19937 rng((unsigned int) chrono::steady_clock::now().time_since_epoch().count());

// random integer in [l,r]
int getRand(int l, int r)
{
    /*
        // you can also use this to get random permutation of indexes
        vector<int> order(n);
        iota(order.begin(), order.end(), 0);
        shuffle(order.begin(), order.end(), rng);
    */
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

void solve_LOG()
{
    int n,m,p;
    cin>>n>>m>>p;

    vector <string> v(n);
    F(i,0,n-1)
    {
        cin>>v[i];
    }

    int mx=0;
    string ans(m,'0');
    // int mxiter=30;
    vector<int> order(n);
    iota(order.begin(), order.end(), 0);
    shuffle(order.begin(), order.end(), rng);
    
    // while (mxiter--)
    F(z,0,min(n-1,30ll))
    {
        // int ind=getRand(0,n-1);
        int ind=order[z];

        vector<int> exact_cnt((int)pow(2,15),0);

        F(i,0,n-1)
        {
            int sum=0;
            int pww=1;
            RF(j,m-1,0)
            {
                if(v[ind][j]=='0')continue;
                if(v[i][j]=='1')
                {
                    sum+=pww;
                }
                pww*=2;
            }
            exact_cnt[sum]++;
        }

        vector<int> super_set_cnt((int)pow(2,15),0);

        for(int mask=0;mask<(int)pow(2,15);mask++)
        {
            for(int submask=mask;submask>0;submask=(submask-1)&mask)
            {
                super_set_cnt[submask]+=exact_cnt[mask];
                if(super_set_cnt[submask]>=(n+1)/2)
                {
                    if(mx<__builtin_popcountll(submask))
                    {
                        mx=__builtin_popcountll(submask);
                        int bit=0;
                        RF(j,m-1,0)
                        {
                            if(v[ind][j]=='0')
                            {
                                ans[j]='0';
                            }
                            else
                            {
                                if((submask>>bit)&1)ans[j]='1';
                                else ans[j]='0';
                                bit++;
                            }
                        }
                    }
                }
            }
        }

    }

    cout<<ans;

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    fact_init();
#endif
    // cout<<fixed<<setprecision(10);
    int _t=1;
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}
//	parsed : 03-June-2021 14:42:38 IST