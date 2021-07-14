//https://codeforces.com/contest/1504/problem/D

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 03-April-2021 21:05:30 IST
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
    int n;
    cin>>n;

    set <pair <int,int> > v1;
    set <pair <int,int> > v2;

    int vis[n+1][n+1]={};

    F(i,1,n)
    {
        F(j,1,n)
        {
            if((i+j)%2)v1.insert({i,j});
            else v2.insert({i,j});
        }
    }

    int grid[n+1][n+1]={};

    F(m,1,n*n)
    {
        int x;
        cin>>x;

        set<int> zz;
        zz.insert(1);
        zz.insert(2);
        zz.insert(3);

        zz.erase(x);

        int t1=*zz.begin();
        int t2=*zz.rbegin();

        if(zz.find(1)!=zz.end() && !v1.empty())
        {
            pair <int,int> p=*v1.begin();
            v1.erase(v1.begin());

            cout<<1<<" "<<p.X<<" "<<p.Y<<endl;
            grid[p.X][p.Y]=1;
            continue;
        }
        if(zz.find(3)!=zz.end() && !v2.empty())
        {
            pair <int,int> p=*v2.begin();
            v2.erase(v2.begin());

            cout<<3<<" "<<p.X<<" "<<p.Y<<endl;
            grid[p.X][p.Y]=3;
            continue;
        }

        if(!v1.empty())
        {
            pair <int,int> p=*v1.begin();
            v1.erase(v1.begin());

            cout<<2<<" "<<p.X<<" "<<p.Y<<endl;
            grid[p.X][p.Y]=2;
        }

        if(!v2.empty())
        {
            pair <int,int> p=*v2.begin();
            v2.erase(v2.begin());

            cout<<2<<" "<<p.X<<" "<<p.Y<<endl;
            grid[p.X][p.Y]=2;
        }

    }
}

signed main()
{
    // ios_base::sync_with_stdio(false);
    // cin.tie(nullptr);
    // cout.tie(nullptr);
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