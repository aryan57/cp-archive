//https://codeforces.com/contest/1516/problem/D

/*
    author : aryan57
    created : 27-April-2021 10:18:33 IST
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

#define ARYAN_SIEVE  
const int mxn_sieve = 1e5;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i <= mxn_sieve; i++)
        spf[i] = i;

    for (int i = 4; i <= mxn_sieve; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i <= mxn_sieve; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= mxn_sieve; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void solve_LOG()
{
    int n,q;
    cin>>n>>q;

    int a[n];
    F(i,0,n-1)
    {
        cin>>a[i];
    }

    vector <int> go(n,INF);

    vector <int> prime_min_pos(mxn+1,n);

    RF(i,n-1,0)
    {
        int x=a[i];
        int mn=n;
        while (x!=1)
        {
            int prime=spf[x];
            mn=min(mn,prime_min_pos[prime]);
            prime_min_pos[prime]=i; 
            
            while(x%prime==0)
            {
                x/=prime;
            }
        }
        go[i]=mn;
        if(i<n-1)go[i]=min(go[i],go[i+1]);
    }

    vector< vector<int> > dp(18,vector <int> (n,INF));

    F(bit,0,17)
    {
        F(i,0,n-1)
        {
            if(bit==0){
                assert(i<go[i]);
                dp[bit][i]=go[i];
            }else{
                if(dp[bit-1][i]<n)
                    dp[bit][i]=dp[bit-1][dp[bit-1][i]];
                else dp[bit][i]=n;
            }
        }
    }

    while(q--){
        int l,r;
        cin>>l>>r;
        --l;--r;

        int ans=0;
        int cur=l;
        RF(bit,17,0)
        {
            if(dp[bit][cur]>r)continue;

            cur=dp[bit][cur];
            ans+=(int)pow(2,bit);
        }
        cout<<ans+1;
        cout<<"\n";
    }
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