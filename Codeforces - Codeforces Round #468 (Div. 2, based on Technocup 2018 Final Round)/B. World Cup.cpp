/*
	group : Codeforces - Codeforces Round #468 (Div. 2, based on Technocup 2018 Final Round)
	name : B. World Cup.cpp
	srcPath : /home/aryan/Documents/cp/B_World_Cup.cpp
	url : https://codeforces.com/contest/931/problem/B
*/
/*
    author : aryan57
    created : 08-June-2021 23:13:25 IST
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

    vector <int> adj[1000];
bool dfs(int u,int x)
{
    if(u==x)return true;

    if(sz(adj[u])==2 && (dfs(adj[u][0],x) || dfs(adj[u][1],x)))return true;

    return false;
}

void solve_LOG()
{
    int n;
    cin>>n;
    int a,b;
    cin>>a>>b;


    int p=n+1;

    vector <int> cur(n);
    iota(all(cur),1);
    vector <int> height(1000,0);
    int h=0;
    while (sz(cur)>1)
    {
        ++h;
        vector <int> temp;
        for(int i=0;i<sz(cur);i+=2)
        {
            adj[p].push_back(cur[i]);
            adj[p].push_back(cur[i+1]);
            height[cur[i]]=height[cur[i+1]]=h;
            temp.push_back(p);
            p++;
        }

        cur.clear();
        swap(cur,temp);
        
    }

    p--;
    // dbg(p);
    if(a>b)swap(a,b);
    RF(i,p,n+1)
    {
        if(dfs(adj[i][0],a) && dfs(adj[i][1],b))
        {
            if(i==p)cout<<"Final!";
            else cout<<height[i]-1;
            cout<<"\n";
            return ;
        }
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
//	parsed : 08-June-2021 23:13:05 IST