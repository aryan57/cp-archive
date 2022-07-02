/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 15:52:02 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<vector<pair<int,int> >  > adj(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back({v,0});
		adj[v].push_back({u,1});
	}

	vector <int> valdown(n),valup(n);

	function<void(int,int)> dfs_down = [&](int u,int par){
		int ans=0;
		for(auto e : adj[u]){
			int to = e.first;
			if(to==par)continue;
			int w = e.second;
			dfs_down(to,u);
			ans+=w+valdown[to];
		}
		valdown[u]=ans;
	};

	function<void(int,int)> dfs_up = [&](int u,int par){
		
		for(auto e : adj[u]){
			int to = e.first;
			if(to==par)continue;
			int w = e.second;

			int rest=valdown[u];
			rest-=valdown[to]+w;

			int tot=rest + valup[u]  + 1-w;
			valup[to]=tot;
			dfs_up(to,u);
		}
	};

	dfs_down(0,-1);
	dfs_up(0,-1);

	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		v[i] = {valdown[i]+valup[i],i};
	}

	sort(v.begin(),v.end());

	cout<<v[0].first<<"\n";
	for(int i=0;i<n;i++){
		if(v[i].first==v[0].first)cout<<v[i].second+1<<" ";
		else break;
	}
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}