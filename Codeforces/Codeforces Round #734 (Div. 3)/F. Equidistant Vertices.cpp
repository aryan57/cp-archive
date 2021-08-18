/*
	group : Codeforces - Codeforces Round #734 (Div. 3)
	name : F. Equidistant Vertices.cpp
	srcPath : /home/aryan/Documents/cp/F_Equidistant_Vertices.cpp
	url : https://codeforces.com/contest/1551/problem/F
*/
/*
    author : aryan57
    created : 24-July-2021 00:43:49 IST
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

#define ARYAN_FACT
const int mxn_fact=1e2;
int fact[mxn_fact+1];

void fact_init()
{
    int MOD=M;
    fact[0]=1;
    for (int i=1;i<=mxn_fact;i++)
        fact[i]=(i*fact[i-1])%MOD;
}
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
int ncr(int n,int r)
{
    if(r>n)return 0;
    int ans=1;
    ans*=fact[n];
    ans%=M;
    ans*=binpow(fact[r]);
    ans%=M;
    ans*=binpow(fact[n-r]);
    ans%=M;
    return ans;
}

void dfs(int root,int u,int par,int cur,vector< vector<int> > &adj,vector< vector<int> >  &dis)
{
    dis[root][u]=cur;
    for(int to : adj[u])
    {
        if(to==par)continue;
        dfs(root,to,u,cur+1,adj,dis);
    }
}

void solve_LOL()
{
    int n,p;
    cin>>n>>p;

    vector< vector<int> > adj(n);

    F(i,0,n-2)
    {
        int u,v;
        cin>>u>>v;
        --u;--v;
        adj[u].push_back(v);
        adj[v].push_back(u);
    }

    if(p==2)
    {
        cout<<ncr(n,2);
        cout<<"\n";
        return;
    }

    vector< vector<int> > dis(n,vector <int> (n,-1));

    F(i,0,n-1)
    {
        dfs(i,i,-1,0,adj,dis);
    }

    vector <int> vis_dis(n);

    int ans=0;
    F(i,0,n-1)
    {
        F(j,i+1,n-1)
        {
            if(vis_dis[dis[i][j]])continue;
            vis_dis[dis[i][j]]=true;
            int cnt=0;
            F(k,0,n-1)
            {
                if(k!=i && k!=j && dis[k][i]==dis[k][j] && dis[k][i]==dis[i][j])cnt++;
            }

            // dbg(n,p,i,j,cnt);

            ans+=ncr(cnt,p-2);
            ans%=M;
        }
    }

    cout<<ans;
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
//	parsed : 24-July-2021 24:42:56 IST