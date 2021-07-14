//https://codeforces.com/contest/1484/problem/C

/*
    author : Aryan Agarwal, IIT Kharagpur
    created : 21-March-2021 19:32:31 IST
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

int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

int val[mxn]={};
vector <int> f[mxn];
bool comp(int  a, int  b)
{
    return val[a]<val[b];
}

bool comp2(int x,int y)
{
    return sz(f[x])<sz(f[y]);
}

void solve_LOL()
{
    int n,m;
    cin>>n>>m;

    F(i,0,mxn-1)
    {
        val[i]=0;
        f[i].clear();
    }

    int zz=ceil(m,2);
    // dbg(zz);

    vector <int> ans(m);
    

    vector <int> ind(m);
    iota(all(ind),0);

    F(j,0,m-1)
    {
        int k;
        cin>>k;

        
        F(i,0,k-1)
        {
            int t;
            cin>>t;
            --t;
            f[j].pb(t);
        }

        

    }

    sort(all(ind),comp2);

    for(int j : ind)
    {
        sort(all(f[j]),comp);

        if(val[f[j][0]]==zz)
        {
            cout<<"NO\n";
            return;
        }

        val[f[j][0]]++;
        ans[j]=f[j][0];
    }

    

    cout<<"YES\n";
    for(int x : ans)cout<<x+1<<" ";
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}