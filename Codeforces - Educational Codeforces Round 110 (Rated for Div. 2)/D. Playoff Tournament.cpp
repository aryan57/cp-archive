/*
	group : Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
	name : D. Playoff Tournament.cpp
	srcPath : /home/aryan/Documents/cp/D_Playoff_Tournament.cpp
	url : https://codeforces.com/contest/1535/problem/D
*/
/*
    author : aryan57
    created : 04-June-2021 21:32:14 IST
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

const int mxn = 3e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);
string s;
int k,n;
vector <int> val(mxn+1);
vector <int> adj[mxn+1];
vector <int> par(mxn+1);

int dfs(int u)
{
    if(sz(adj[u])==1)
    {
        int ans=1;
        if(s[u]=='?')ans=2;
        val[u]=ans;
        return ans;
    }
    int ans=0;
    int l=dfs(adj[u][0]);
    int r=dfs(adj[u][1]);
    if(s[u]=='0')ans=l;
    if(s[u]=='1')ans=r;
    if(s[u]=='?')ans=l+r;
    val[u]=ans;
    return ans;
}

void solve_LOG()
{
    
    cin>>k;
    cin>>s;
    n=sz(s);
    s='#'+s;
    

    vector <int> cur;
    F(i,1,(int)pow(2,k-1))
    {
        cur.push_back(i);
    }
    int p=(int)pow(2,k-1)+1;
    
    RF(h,k,1)
    {
        vector <int> temp;
        for(int i=0;i<=sz(cur)-2;i+=2)
        {
            adj[cur[i]].push_back(p);
            adj[p].push_back(cur[i]);
            adj[cur[i+1]].push_back(p);
            adj[p].push_back(cur[i+1]);
            par[cur[i]]=p;
            par[cur[i+1]]=p;
            temp.push_back(p);
            p++;
        }
        cur.clear();
        cur=temp;
    }

    par[n]=-1;

    dfs(n);

    // F(i,1,n)
    // {
    //     dbg(i);
    //     dbg(adj[i]);
    // }
    // dbg(par);

    
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
//	parsed : 04-June-2021 21:32:11 IST