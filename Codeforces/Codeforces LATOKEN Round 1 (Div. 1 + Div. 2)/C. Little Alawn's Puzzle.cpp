/*
	group : Codeforces - Codeforces LATOKEN Round 1 (Div. 1 + Div. 2)
	name : C. Little Alawn's Puzzle.cpp
	srcPath : /home/aryan/Documents/cp/C_Little_Alawn_s_Puzzle.cpp
	url : https://codeforces.com/contest/1534/problem/C
*/
/*
    author : aryan57
    created : 13-June-2021 21:34:22 IST
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

const int mxn = 4e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

/*
    modInverse(a) = binpow(a, phi(n)-1, n)
    If n is prime, phi(n) = n-1
    phi(n) = number of no.s from 1 to n co-prime with n
*/
int binpow(int a, int b=M-2, int m=M)
{
    assert(a>=0 && b>=0);
    a%=m;
    int res=1;
    while (b)
    {
        if(b%2)res=res*a%m;
        a=a*a%m;
        b/=2;
    }
    return res;
}

vector <int> adj[mxn+1];
vector <bool> vis(mxn+1);

void dfs(int u,int st)
{
    if(vis[u])return;
    vis[u]=true;
    dfs(adj[u][0],st);
}

void solve_LOL()
{
    int n;
    cin>>n;

    F(i,0,n)
    {
        adj[i].clear();
        vis[i]=false;
    }

    vector <int> a(n+1),b(n+1);

    F(i,1,n)
    {
        cin>>a[i];
    }
    F(i,1,n)
    {
        cin>>b[i];
        adj[a[i]].push_back(b[i]);
    }

    int cnt=0;

    F(i,1,n)
    {
        if(!vis[i])
        {
            cnt++;
            dfs(i,i);
        }
    }

    cout<<binpow(2,cnt);
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}
//	parsed : 13-June-2021 21:34:15 IST