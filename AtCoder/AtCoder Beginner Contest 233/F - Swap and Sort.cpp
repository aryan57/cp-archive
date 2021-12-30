/*
	group : AtCoder - AtCoder Beginner Contest 233
	name : F - Swap and Sort.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Swap_and_Sort.cpp
	url : https://atcoder.jp/contests/abc233/tasks/abc233_f
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.12.2021 10:29:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

/* 
	dsu d(int n)
	// It creates an undirected graph with n vertices and 0 edges.
	// 0<=n<=1e8
	// O(n)

	int d.merge(int a, int b)
	// It adds an edge (a, b)
	// If the vertices a and b were in the same connected component, it returns the representative of this connected component. Otherwise, it returns the representative of the new connected component.
	// 0<=a<n   0<=b<n
	// O(alpha(n)) amortized

	bool d.same(int a, int b)
	// Returns whether the vertices a and b are in the same connected component
	// 0<=a<n   0<=b<n
	// O(alpha(n)) amortized

	int d.leader(int a)
	// Returns the representative of the connected component that contains the vertex a
	// 0<=a<n
	// O(alpha(n)) amortized

	int d.size(int a)
	// Returns the size of the connected component that contains the vertex a.
	// 0<=a<n
	// O(alpha(n)) amortized

	vector<vector<int>> d.groups()
	// Returns the list of the "list of the vertices in a connected component"
	// O(n)
*/
struct dsu {
  public:
	dsu() : _n(0) {}
	dsu(int n) : _n(n), parent_or_size(n, -1) {}

	int merge(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		int x = leader(a), y = leader(b);
		if (x == y) return x;
		if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
		parent_or_size[x] += parent_or_size[y];
		parent_or_size[y] = x;
		return x;
	}

	bool same(int a, int b) {
		assert(0 <= a && a < _n);
		assert(0 <= b && b < _n);
		return leader(a) == leader(b);
	}

	int leader(int a) {
		assert(0 <= a && a < _n);
		if (parent_or_size[a] < 0) return a;
		return parent_or_size[a] = leader(parent_or_size[a]);
	}

	int size(int a) {
		assert(0 <= a && a < _n);
		return -parent_or_size[leader(a)];
	}

	std::vector<std::vector<int>> groups() {
		std::vector<int> leader_buf(_n), group_size(_n);
		for (int i = 0; i < _n; i++) {
			leader_buf[i] = leader(i);
			group_size[leader_buf[i]]++;
		}
		std::vector<std::vector<int>> result(_n);
		for (int i = 0; i < _n; i++) {
			result[i].reserve(group_size[i]);
		}
		for (int i = 0; i < _n; i++) {
			result[leader_buf[i]].push_back(i);
		}
		result.erase(
			std::remove_if(result.begin(), result.end(),
						   [&](const std::vector<int>& v) { return v.empty(); }),
			result.end());
		return result;
	}

  private:
	int _n;
	// root node: -1 * component size
	// otherwise: parent
	std::vector<int> parent_or_size;
};


void solve()
{
	int n;
	cin>>n;
	vector <int> p(n);
	vector <int> pos(n);
	vector <int> deg(n);
	vector <int> parent(n,-1);
	vector <int> parent_edge_no(n,-1);
	for(int i=0;i<n;i++){
		cin>>p[i];
		p[i]--;
		pos[p[i]]=i;
	}
	int m;
	cin>>m;
	dsu d(n);
	vector< vector<pair <int,int> > > adj(n);
	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a;--b;
		if(!d.same(a,b)){
			d.merge(a,b);
			adj[a].push_back({b,i+1});
			adj[b].push_back({a,i+1});
			deg[a]++;
			deg[b]++;
		}
	}

	for(int i=0;i<n;i++){
		if(!d.same(i,pos[i])){
			cout<<"-1\n";
			return;
		}
	}

	function<void(int,int,int)> dfs = [&](int u,int par,int no){
		parent[u]=par;
		parent_edge_no[u]=no;
		for(auto to : adj[u]){
			if(to.first!=par){
				dfs(to.first,u,to.second);
			}
		}
	};

	vector <int> ans;
	// forest,  each vector nodes represent a tree
	vector< vector<int> > g = d.groups();

	for(auto &v : g){
		// each vector v is a connected component
		// we will solve them independently

		// all the nodes in the vector v forms a tree
		// we will process each tree with leaves going first, and keep on
		// removing the leaves

		set<pair <int,int>> pq;
		for(int x : v){
			if(deg[x])pq.insert({deg[x],x});
		}

		while (!pq.empty()){
			int leaf = pq.begin()->second;
			pq.erase(pq.begin());
			assert(deg[leaf]==1);
			int node = pos[leaf];
			assert(d.same(leaf,node));

			// the (leaf)th piece is at node.
			// We will move the piece from node to leaf
			// then cut the leaf from tree
			dfs(leaf,-1,-1);
			int cur=node;
			while (cur!=leaf){
				int edge=parent_edge_no[cur];
				int new_node=parent[cur];
				assert(new_node!=-1 && edge!=-1);

				// swap the pieces at cur and new_node using edge
				// and make cur to new_node
				swap(p[cur],p[new_node]);
				pos[p[cur]]=cur;
				pos[p[new_node]]=new_node;
				ans.push_back(edge);
				cur=new_node;
			}

			assert(adj[leaf].size()==1);
			int par = adj[leaf][0].first;
			adj[leaf].clear();
			for(auto it=adj[par].begin();it!=adj[par].end();it++){
				if(it->first==leaf){
					adj[par].erase(it);
					break;
				}
			}
			pq.erase({deg[par],par});
			deg[par]--;
			if(deg[par])pq.insert({deg[par],par});
		}
	}

	cout<<ans.size()<<"\n";
	for(int x : ans)cout<<x<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 30-December-2021 10:00:12 IST