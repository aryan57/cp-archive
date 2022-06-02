/**
 *    author:  Aryan Agarwal
 *    created: 06.05.2022 11:48:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	int x,y;
	cin>>x>>y;
	--x;--y;

	vector <int> a(k);
	for(int &ai : a){
		cin>>ai;
		--ai;
	}

	a.push_back(y);

	vector< vector<int> > adj(n);
	vector <int> depth(n),parent(n);
	vector <bool> visited(n);

	for(int e=1;e<n;e++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	
	function<void(int,int,int)> dfs = [&](int u,int par,int dep){
		parent[u]=par;
		depth[u]=dep;
		for(int to : adj[u]){
			if(to!=par)dfs(to,u,dep+1);
		}
	};
	function<void(int,int&)> dfs2 = [&](int u,int &cost){
		if(visited[u])return;
		visited[u]=true;
		if(parent[u]==u)return;
		cost+=2;
		dfs2(parent[u],cost);
	};

	dfs(x,x,0);

	int cost=0;
	for(int ai : a)dfs2(ai,cost);
	cost-=depth[y];

	cout<<cost<<"\n";
}

signed main()
{
	// ios_base::sync_with_stdio(false);
	// cin.tie(nullptr);
	cin.tie(0)->sync_with_stdio(0);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}