//https://codeforces.com/contest/673/problem/D

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 12-April-2021 13:27:13 IST
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

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_LOG()
{
    int n,k,a,b,c,d;
    cin>>n>>k>>a>>b>>c>>d;

    if(n==4 || k<n+1)
    {
        cout<<"-1\n";
        return;
    }



    int cnt[n+1]={};
    cnt[a]++;
    cnt[b]++;
    cnt[c]++;
    cnt[d]++;

    vector <int> ava;
    F(i,1,n)
    {
        if(!cnt[i])ava.push_back(i);
    }

    if(n==5)
    {
        cout<<a<<" "<<c<<" "<<ava[0]<<" "<<d<<" "<<b;
        cout<<"\n";
        cout<<c<<" "<<a<<" "<<ava[0]<<" "<<b<<" "<<d;
        cout<<"\n";

        return;
    }
    
    vector <int> p1;
    p1.pb(a);
    p1.pb(c);

    for(int i=0;i<sz(ava)-1;i++)
    {
        p1.push_back(ava[i]);
    }
    p1.push_back(d);
    p1.push_back(ava.back());
    p1.push_back(b);

    vector <int> p2;
    p2.push_back(c);
    p2.push_back(a);
    p2.push_back(p1[sz(p1)-2]);
    p2.push_back(b);

    F(i,2,sz(p1)-3)
    {
        p2.push_back(p1[i]);
    }

    for(int x : p1)cout<<x<<" ";
    cout<<"\n";
    for(int x : p2)cout<<x<<" ";
    cout<<"\n";
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