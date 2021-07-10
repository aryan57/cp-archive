/*
	group : Codeforces - Codeforces Round #731 (Div. 3)
	name : G. How Many Paths?.cpp
	srcPath : /home/aryan/Documents/cp/G_How_Many_Paths_.cpp
	url : https://codeforces.com/contest/1547/problem/G
*/
/*
    author : aryan57
    created : 10-July-2021 21:33:39 IST
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

// #define int long long
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

int n;
vector<int> adj[mxn+1];
vector<int> parents[mxn+1];
vector<char> color(mxn,0);
vector<int> parent(mxn,-1);
int cycle_start, cycle_end;
vector <int> ans(mxn+1);

bool dfs(int v) {
    color[v] = 1;
    for (int u : adj[v]) {
        if(ans[u]==-1)continue;
        if (color[u] == 0) {
            parent[u] = v;
            if (dfs(u))
                return true;
        } else if (color[u] == 1) {
            cycle_end = v;
            cycle_start = u;
            return true;
        }
    }
    color[v] = 2;
    return false;
}

bool find_cycle() {
    
    
    cycle_start = -1;

    for (int v = 1; v <= n; v++)
    {
        if (ans[v]!=-1 && color[v] == 0 && dfs(v))break;
    }

    if (cycle_start == -1)return false;

    dbg(cycle_start,cycle_end);
    
    vector<int> cycle;
    cycle.push_back(cycle_start);
    // int cnt=0;
    for (int v = cycle_end; v != cycle_start && v!=-1; v = parent[v])
    {
        cycle.push_back(v);
        // if(cnt++>10)break;
        // dbg(v);

    }
    // cycle.push_back(cycle_start);
    // reverse(cycle.begin(), cycle.end());

    // dbg(cycle);

    // for (int v : cycle)
    // {
    //     queue<int> q;
    //     vector<bool> visited(n+1);
    //     vector <int> temp;
        
    //     q.push(v);
    //     visited[v] = true;
    //     temp.push_back(v);
        
    //     while (!q.empty()) {
        
    //         int parent_node = q.front();
    //         q.pop();
        
    //         for (int child_node : adj[parent_node]) {
        
    //             if (!visited[child_node] && ans[child_node]!=-1)
    //             {
    //                 visited[child_node] = true;
    //                 temp.push_back(child_node);
    //                 q.push(child_node);
    //             }
    //         }
    //     }

    //     for(int z : temp)
    //     {
    //         ans[z]=-1;
    //         adj[z].clear();
    //         parents[z].clear();
    //     }
    // }

    return true;
    
}

void solve_LOG()
{
    int m;
    cin>>n>>m;

    F(i,0,n)
    {
        adj[i].clear();
        parents[i].clear();
        color[i]=0;
        parent[i]=-1;
        ans[i]=0;
        cycle_start=-1;
        cycle_end=-1;
    }

    F(i,1,m)
    {
        int u,v;
        cin>>u>>v;
        adj[u].push_back(v);
        parents[v].push_back(u);
    }

    

    {
        queue<int> q;
        vector<bool> visited(n+1);
        
        q.push(1);
        visited[1] = true;
        
        while (!q.empty()) {
        
            int parent_node = q.front();
            q.pop();
        
            for (int child_node : adj[parent_node]) {
        
                if (!visited[child_node])
                {
                    visited[child_node] = true;
                    q.push(child_node);
                }
            }
        }

        F(i,1,n)
        {
            if(visited[i])
            {
                ans[i]=1;
            }else
            {
                adj[i].clear();
                parents[i].clear();
            }
        }
    }

    int cnt=0;
    while (find_cycle()){
        // F(i,1,n)cout<<ans[i]<<" ";
        // cout<<"\n";
        // F(i,1,n)dbg(i,adj[i]);

        // if(cnt++>0)
        // break;
    }
    
    // {
    //     queue<int> q;
    //     vector<bool> visited(n+1);
    //     vector <int> temp;
        
    //     q.push(1);
    //     visited[1] = true;
    //     temp.push_back(1);
        
    //     while (!q.empty()) {
        
    //         int parent_node = q.front();
    //         q.pop();
        
    //         for (int child_node : adj[parent_node]) {
        
    //             if (!visited[child_node])
    //             {
    //                 visited[child_node] = true;
    //                 temp.push_back(child_node);
    //                 q.push(child_node);
    //             }
    //         }
    //     }

    //     for(int z : temp)
    //     {
    //         int cnt=0;

    //         for(int p : parents[z])
    //         {
    //             if(visited[p])cnt++;
    //             if(cnt>1)break;
    //         }
    //         // assert(cnt>0);
    //         if(cnt>1)ans[z]=2;
    //     }
    // }

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
        solve_LOG();
    }
    return 0;
}
//	parsed : 10-July-2021 20:07:54 IST