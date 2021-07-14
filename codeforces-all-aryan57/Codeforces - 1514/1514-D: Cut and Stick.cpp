//https://codeforces.com/contest/1514/problem/D

/*
    // editorial used
    author : aryan57
    created : 19-April-2021 22:49:34 IST
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

mt19937 rng(chrono::steady_clock::now().time_since_epoch().count());
 
int getRand(int l, int r)
{
    uniform_int_distribution<int> uid(l, r);
    return uid(rng);
}

void solve_LOG()
{
    int n,q;
    cin>>n>>q;

    vector <int> val[n+1];
    vector <int> a(n);

    F(i,0,n-1)
    {
        cin>>a[i];
        val[a[i]].push_back(i);
    }

    while (q--)
    {
        int l,r;
        cin>>l>>r;
        --l;--r;

        int mx_tries=50;

        int mxval=0;
        int len=r-l+1;

        while (mx_tries--)
        {
            int ind=getRand(l,r);
        
            int tt=upper_bound(val[a[ind]].begin(),val[a[ind]].end(),r)-lower_bound(val[a[ind]].begin(),val[a[ind]].end(),l);
            // dbg(a[ind],tt,l,r);

            mxval=max(tt,mxval);
        }

        int zz=1;
 
        if(mxval>(len+1)/2)
        {
            zz=2*mxval-len;
        }
        
        cout<<zz;
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