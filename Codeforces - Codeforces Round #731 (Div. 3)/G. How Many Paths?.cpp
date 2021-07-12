/*
	group : Codeforces - Codeforces Round #731 (Div. 3)
	name : G. How Many Paths?.cpp
	srcPath : /home/aryan/Documents/cp/G_How_Many_Paths_.cpp
	url : https://codeforces.com/contest/1547/problem/G
*/
/*
    // credits : @nikhiltudaha
    author : aryan57
    created : 12-July-2021 17:14:09 IST
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

enum Color{
    white,  // not processed
    grey,  // in process
    black  // processed
};

vector <int> adj[mxn+1];
vector <Color> color(mxn+1);
vector <bool> is_more_than_1(mxn+1);
vector <bool> is_part_of_a_cycle(mxn+1);
vector <int> ans(mxn+1);

void dfs(int u)
{
    ans[u]=1;
    color[u]=grey;
    for(int to : adj[u])
    {
        if(color[to]==white)
        {
            dfs(to);
        }
        else if(color[to]==grey)
        {
            is_part_of_a_cycle[to]=true;
            is_part_of_a_cycle[u]=true;
        }
        else
        {
            is_more_than_1[to]=true;
        }
    }
    color[u]=black;
}

void solve_LOL()
{
    int n,m;
    cin>>n>>m;

    F(i,0,n)
    {
        adj[i].clear();
        color[i]=white;
        is_more_than_1[i]=false;
        is_part_of_a_cycle[i]=false;
        ans[i]=0;
    }

    F(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
    }

    dfs(1);
    // now all nodes which can be visited will be 1 and rest will be 0
    

    {
        vector<bool> visited(n+1);

        F(i,1,n)
        {
            if(ans[i]==1 && is_part_of_a_cycle[i] && !visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                ans[i]=-1;
                while (!q.empty()) {
                
                    int parent_node = q.front();
                    q.pop();
                
                    for (int child_node : adj[parent_node]) {
                
                        if (!visited[child_node])
                        {
                            visited[child_node] = true;
                            ans[child_node] = -1;
                            q.push(child_node);
                        }
                    }
                }
            }
        }

        // now all nodes which can be visited will by only one path will be 1,
        // by infinite paths will be -1
        // by no paths will be 0
    }

    {
        vector<bool> visited(n+1);

        F(i,1,n)
        {
            if(ans[i]==1 && is_more_than_1[i] && !visited[i])
            {
                queue<int> q;
                q.push(i);
                visited[i] = true;
                ans[i]=2;
                while (!q.empty()) {
                
                    int parent_node = q.front();
                    q.pop();
                
                    for (int child_node : adj[parent_node]) {
                
                        if (!visited[child_node])
                        {
                            visited[child_node] = true;
                            if(ans[child_node]==1)ans[child_node] = 2;
                            q.push(child_node);
                        }
                    }
                }
            }
        }
    }

    F(i,1,n)cout<<ans[i]<<" ";cout<<"\n";
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
//	parsed : 12-July-2021 17:13:51 IST