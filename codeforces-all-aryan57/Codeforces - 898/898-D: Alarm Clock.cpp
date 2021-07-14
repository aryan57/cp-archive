//https://codeforces.com/contest/898/problem/D

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 16-April-2021 14:34:27 IST
*/

#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e6;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

int fun(vector <int> &a,int n ,int m,int k)
{
    set<int,greater<int> > s;

    int ans=0;

    int cnt[mxn+10]={};
    F(i,0,n-1)cnt[a[i]]++;

    F(i,1,m)
    {
        if(cnt[i])s.insert(i);
    }

    F(i,m,mxn+5)
    {
        while(sz(s)>=k)
        {
            s.erase(s.begin());
            ans++;
        }
        s.erase(i-m+1);
        if(cnt[i+1])s.insert(i+1);
    }

    return ans;
}
int fun2(vector <int> &a,int n ,int m,int k)
{
    set<int> s;

    int ans=0;

    int cnt[mxn+10]={};
    F(i,0,n-1)cnt[a[i]]++;

    RF(i,mxn,mxn-m+1)
    {
        if(cnt[i])s.insert(i);
    }

    RF(i,mxn-m+1,1)
    {
        while(sz(s)>=k)
        {
            s.erase(s.begin());
            ans++;
        }
        s.erase(i+m-1);
        if(cnt[i-1])s.insert(i-1);
    }

    return ans;
}

void solve_LOG()
{
    int n,m,k;
    cin>>n>>m>>k;

    vector <int> a(n);
    F(i,0,n-1)
    cin>>a[i];

    int ans=INF;
    

    ans=min(ans,fun(a,n,m,k));
    ans=min(ans,fun2(a,n,m,k));

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
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
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