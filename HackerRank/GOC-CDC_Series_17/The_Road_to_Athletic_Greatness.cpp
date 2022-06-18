/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 16:08:16 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int mxn = 3e5;
vector <int> adj[mxn+1];
vector <bool> has(mxn+1);
int n,k,root;

bool dfs1(int u,int par=-1){
	for(int to : adj[u]){
		if(to==par)continue;
		if(dfs1(to,u))has[u]=true;
	}
	return has[u];
}

int dfs(int u,int par=-1){
	int ans=0;
	for(int to : adj[u]){
		if(has[to] && to!=par){
			ans+=2+dfs(to,u);
		}
	}
	return ans;
}

void solve()
{
	cin>>n>>k>>root;
	for(int i=1;i<=k;i++){
		int x;
		cin>>x;
		has[x]=true;
	}
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	dfs1(root);
	cout<<dfs(root);
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