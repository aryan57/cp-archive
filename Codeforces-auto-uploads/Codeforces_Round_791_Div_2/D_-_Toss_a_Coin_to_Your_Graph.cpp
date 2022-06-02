/**
 *    author:  Aryan Agarwal
 *    created: 14.05.2022 16:10:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	using pii = pair<int,int> ;
	vector<vector<int>> adj(n);
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
	}

	const int inf = 2e18;
	int ans=inf;
	int l=1;
	int r=1e9;

	while(l<=r){
		int m=(l+r)/2;

		vector<int> topo;
		vector<bool> vis(n);

		function<void(int)> dfs = [&](int u){
			vis[u]=true;
			for(int to : adj[u]){
				if(!vis[to] && a[to]<=m)dfs(to);
			}
			topo.push_back(u);
		};

		for(int i=0;i<n;i++){
			if(!vis[i] && a[i]<=m)dfs(i);
		}
		reverse(topo.begin(),topo.end());

		bool hascycle=false;
		vector<bool> used(n);

		for(int u : topo){
			used[u]=true;
			for(int to : adj[u]){
				if(used[to]){
					hascycle=true;
					break;
				}
			}
			if(hascycle)break;
		}

		if(hascycle){
			ans=min(ans,m);
			r=m-1;
			continue;
		}

		vector<int> dp(n,1);
		int mx=0;
		for(int u : topo){
			mx=max(mx,1ll);
			for(int to : adj[u]){
				if(a[to]<=m){
					dp[to]=max(dp[to],dp[u]+1);
					mx=max(mx,dp[to]);
				}
			}
		}

		if(mx>=k){
			ans=min(ans,m);
			r=m-1;
		}else{
			l=m+1;
		}
	}

	if(ans==inf)ans=-1;
	cout<<ans;

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