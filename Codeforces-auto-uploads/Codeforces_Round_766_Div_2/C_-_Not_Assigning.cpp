#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;
	cin>>n;
	int deg[n+1]={};
	bool ok = true;
	vector<pair<int,int>> adj[n+1];
	int root=-1;
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		deg[u]++;
		deg[v]++;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
		if(deg[u]>2 || deg[v]>2){
			ok=false;
		}
	}
	if(!ok){cout<<"-1\n";return;}
	
	for(int i=0;i<n;i++){
	    if(deg[i]==1){
	        root=i;
	        break;
	    }
	}
	
	assert(root!=-1);
	
	vector<int> ans(n-1);
	function<void(int,int,int,int)> dfs = [&](int u,int par,int id,int ind)-> void{
		if(id==0)ans[ind]=2;
		else ans[ind]=3;
		
		for(auto to : adj[u]){
			if(to.first!=par)dfs(to.first,u,id^1,to.second);
		}
	};
	
	dfs(adj[root][0].first,root,0,adj[root][0].second);
	
		for(int i=0;i<n-1;i++){
			cout<<ans[i]<<" ";
		}
	
	cout<<"\n";
}

signed main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
