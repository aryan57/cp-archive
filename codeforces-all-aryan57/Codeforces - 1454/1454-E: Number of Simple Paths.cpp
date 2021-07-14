//https://codeforces.com/contest/1454/problem/E

// stream help used
// C++ program to print all the cycles
// in an undirected graph
#include <bits/stdc++.h>
using namespace std;
const int N = 200000 + 10;

// variables to be used
// in both functions
vector<int> graph[N];
vector<int> cycles[N];
// #define int long long

// Function to mark the vertex with
// different colors for different cycles
void dfs_cycle(int u, int p, int color[],
               int mark[], int par[], int &cyclenumber)
{

    // already (completely) visited vertex.
    if (color[u] == 2)
    {
        return;
    }

    // seen vertex, but was not completely visited -> cycle detected.
    // backtrack based on parents to find the complete cycle.
    if (color[u] == 1)
    {

        cyclenumber++;
        int cur = p;
        mark[cur] = cyclenumber;

        // backtrack the vertex which are
        // in the current cycle thats found
        while (cur != u)
        {
            cur = par[cur];
            mark[cur] = cyclenumber;
        }
        return;
    }
    par[u] = p;

    // partially visited.
    color[u] = 1;

    // simple dfs on graph
    for (int v : graph[u])
    {

        // if it has not been visited previously
        if (v == par[u])
        {
            continue;
        }
        dfs_cycle(v, u, color, mark, par, cyclenumber);
    }

    // completely visited.
    color[u] = 2;
}

// add the edges to the graph
void addEdge(int u, int v)
{
    graph[u].push_back(v);
    graph[v].push_back(u);
}

// Function to print the cycles
set<int> vec;
void printCycles(int edges, int mark[], int &cyclenumber)
{

    // push the edges that into the
    // cycle adjacency list
    for (int i = 1; i <= edges; i++)
    {
        if (mark[i] != 0)
            cycles[mark[i]].push_back(i);
    }

    // print all the vertex with same cycle
    for (int i = 1; i <= cyclenumber; i++)
    {
        // Print the i-th cycle
        // cout << "Cycle Number " << i << ": ";
        for (int x : cycles[i])
        {
            vec.insert(x);
        }
        break;
    }
}

int dfs1(int u, int par)
{
    int zz = 0;
    zz++;

    for (int v : graph[u])
    {
        if (v != par && vec.find(v)==vec.end())
        {
            zz += dfs1(v, u);
        }
    }

    return zz;
}

// Driver Code
void solve()
{

    int n;
    cin >> n;
    int u, v;
    for (int i = 0; i <= n; i++)
    {
        graph[i].clear();
        cycles[i].clear();
    }
    graph->clear();
    cycles->clear();
    for (int i = 1; i <= n; i++)
    {
        cin >> u >> v;
        addEdge(u, v);
    }

    // arrays required to color the
    // graph, store the parent of node
    int color[N] = {};
    int par[N] = {};

    // mark with unique numbers
    int mark[N] = {};

    // store the numbers of cycle
    int cyclenumber = 0;
    int edges = n;

    // call DFS to mark the cycles
    dfs_cycle(1, 0, color, mark, par, cyclenumber);

    // function to print the cycles
    vec.clear();
    printCycles(edges, mark, cyclenumber);

    long long ans=(long long)n*(n-1ll);
    for (auto it=vec.begin();it!=vec.end();it++)
    {

        int x = dfs1(*it, -1);
        ans-=(long long)x*(x-1ll)/2ll;
        // ans+=x*(n-x);
    }

    cout << ans;
}

signed main()
{
    int t;
    cin >> t;
    while (t--)
    {
        solve();
        cout << "\n";
    }

    return 0;
}