/*
	group : Codeforces - Codeforces Round #467 (Div. 2)
	name : D. Sleepy Game.cpp
	srcPath : /home/aryan/Documents/cp/D_Sleepy_Game.cpp
	url : https://codeforces.com/contest/937/problem/D
*/
/*
    author : aryan57
    created : 08-June-2021 19:29:50 IST
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

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector <int> adj[mxn];

enum Color { White, Grey, Black };
vector<Color> color(mxn,White);

// Returns true if the connected component of
// node 'v' in the directed graph contains any cycle.
bool contains_cycle(int v)
{
    color[v] = Grey;
    for (int u : adj[v])
    {
        if (color[u] == Grey)return true;
        if (color[u] == White && contains_cycle(u))return true;
    }
    color[v] = Black;
    return false;
}

// returns true if the directed graph
// is a DAG(Directed Acyclic Graph) in O(N+M)
bool is_DAG(int N)
{
    for (int v = 0; v < N; v++)
        if (color[v] == White && contains_cycle(v))return false;
    
    return true;
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;
    
    vector<int> out(n);

    F(i,0,n-1)
    {
        cin>>out[i];
        F(j,0,out[i]-1)
        {
            int v;
            cin>>v;
            adj[i].push_back(v-1);
        }
    }

    int s;
    cin>>s;
    --s;

    queue<pair <int,int> > q; //{nodeindex,parity}

    bool visited[n][2]={};
    int parent[n][2]={};
    int distance[n][2]={};
    
    q.push({s,0});
    visited[s][0] = true;
    distance[s][0]=0;
    parent[s][0]=0;

    int found=-1;

    while (!q.empty()) {
    
        int parent_node = (q.front()).X;
        int parity = (q.front()).Y;
        q.pop();
    
        for (int child_node : adj[parent_node])
        {
    
            if (!visited[child_node][parity^1])
            {
                visited[child_node][parity^1] = true;
                q.push({child_node,parity^1});
                distance[child_node][parity^1] = distance[parent_node][parity] + 1;
                parent[child_node][parity^1] = parent_node;

                if(distance[child_node][1]%2 && out[child_node]==0)
                {
                    found=child_node;
                    break;
                }
            }
        }
    }

    if(found!=-1)
    {
        cout<<"Win\n";
        vector<int> v;
        int cur=found;
        int parity=1;
        while (true)
        {
            v.push_back(cur);
            cur=parent[cur][parity];
            parity^=1;

            if(cur==s && parity==0)break;
        }
        v.push_back(s);
        reverse(all(v));
        for(int x : v)
        {
            cout<<x+1<<" ";
        }
        cout<<"\n";
        return;
    }

    if(contains_cycle(s))
    {
        cout<<"Draw\n";
    }
    else
    {
        cout<<"Lose\n";
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
//	parsed : 08-June-2021 19:21:12 IST
//	parsed : 08-June-2021 20:09:38 IST