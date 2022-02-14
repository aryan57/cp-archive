/*
	group : local
	name : Problem_3_Cereal_2.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/darwin/Problem_3_Cereal_2.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/darwin/Problem_3_Cereal_2.cpp
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back
const int maxn = 1e5 + 5;
const int inf = 1e18;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

int n,m, parent[maxn], used[maxn], needdfs[maxn], inans[maxn];

vi ans;
vector<pi> adj[maxn];
vector<pi> starts; // for each connected component

int findRoot(int v) {
    if (parent[v] != v) {
        parent[v] = findRoot(parent[v]);
    }
    return parent[v];
}


void dfs(int v) {
    // dbg(v);
    used[v] = 1;
    needdfs[v]=1;
    for (auto e : adj[v]) {
        if (!used[e.F]) { ans.PB(e.S); dfs(e.F);}
    }
}

signed main() {
    cin >> n >> m;
    for (int i=1; i <=m; i++) parent[i] = i;
    int start = 1, cow = -1;
    for (int i=1; i <=n; i++) {
        int x, y; cin >> x >> y;
        adj[x].PB({y, i}); adj[y].PB({x, i});
        int fx = findRoot(x), fy = findRoot(y);
        if (fx != fy) parent[fx] = fy;
        else {
            starts.PB({x,i});
            //start = x;  // extra edge
            //cow =i;
        }

    }
    for (pi start : starts) {
        int fi = findRoot(start.F);
        // if (!needdfs[fi]) {  // dfs each connected component
            // dbg(fi,start.second);
            ans.push_back(start.second);
            dfs(fi);
            needdfs[fi] = 1;
        // }
    }

    for(int i=1;i<=m;i++){
        int fx = findRoot(i);
        if(!needdfs[fx]){
            dfs(fx);
            needdfs[fx]=1;
        }
    }
    /*
    needdfs[findRoot(start)] = 1;
    ans.PB(cow)
;
    dfs(start);
    for (int i=1; i <=m; i++) {
        int fi = findRoot(i);
        if (!needdfs[fi]) {  // dfs each connected component
            dfs(i);
            needdfs[fi] = 1;
        }
    }
    */

    int sad = 0;
    for (int e : ans) inans[e]=1;
    for (int i=1; i <=n; i++) {
        if (!inans[i]) sad ++;
    }
    cout << sad << "\n";
    for (int e : ans) cout<<e<<"\n";
    for (int i=1; i <=n; i++) {
        if (!inans[i]) cout << i << "\n";
    }

}