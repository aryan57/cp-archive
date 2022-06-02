/**
 *    author:  Aryan Agarwal
 *    created: 02.05.2022 23:27:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<bool> visited_topo;
vector<int> topo_sorted;

const int mxn = 2e5;
vector <int> adj[mxn];

void dfs_topo(int v) {
	visited_topo[v] = true;
	for (int u : adj[v]) {
		if (!visited_topo[u])
			dfs_topo(u);
	}
	topo_sorted.push_back(v);
}

bool topological_sort(int no_of_nodes_topo) {

	visited_topo.assign(no_of_nodes_topo,false);
	topo_sorted.clear();
	for (int i = 0; i < no_of_nodes_topo; ++i) {
		if (!visited_topo[i])
			dfs_topo(i);
	}

	// topo_sorted is the topological sorting
	reverse(topo_sorted.begin(), topo_sorted.end());
	return true;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector <int> in(n);
	while (m--)
	{
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
		in[v]++;
	}
	int ans=1;
	vector <int> dp(n,1);
	topological_sort(n);
	reverse(topo_sorted.begin(),topo_sorted.end());
	for(int u : topo_sorted){
		if(adj[u].size()<2)continue; // out-degree must be atleast 2, so that after decrease, we have atleast 1 outdegree
		for(int v : adj[u]){
			if(in[v]<2)continue; // in-degree must be atleast 2, so that after decrease, we have atleast 1 indegree
			dp[u]=max(dp[u],dp[v]+1);
			ans=max(ans,dp[u]);
		}	
	}
	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}