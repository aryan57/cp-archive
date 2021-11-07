/*
	group : AtCoder - AtCoder Beginner Contest 226
	name : E - Just one.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Just_one.cpp
	url : https://atcoder.jp/contests/abc226/tasks/abc226_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 07.11.2021 18:53:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn = 2e5;
vector< set<int> > adj(mxn);
vector <bool> vis(mxn);
vector <int> deg(mxn);
bool z;

void dfs(int u){
	vis[u]=true;
	if(deg[u]!=2){
		z=false;
	}

	for(int to : adj[u]){
		if(!vis[to]){
			dfs(to);
		}
	}
}

void solve()
{
	int n,m;
	cin>>n>>m;

	
	

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u;
		--v;
		adj[u].insert(v);
		adj[v].insert(u);
		deg[u]++;
		deg[v]++;
	} 
	set<pair <int,int> > pq;
	for(int i=0;i<n;i++){
		if(deg[i]==0){
			cout<<0;
			return;
		}
		pq.insert({deg[i],i});
	}

	while (!pq.empty())
	{
		auto z = *pq.begin();
		if(z.first>1)break;
		int node = z.second;
		assert(deg[node]==1);
		int v = *adj[node].begin();

		pq.erase(pq.begin());
		pq.erase({deg[v],v});

		deg[node]--;
		deg[v]--;

		adj[v].erase(node);
		adj[node].clear();

		if(deg[v]>0)pq.insert({deg[v],v});
	}

	bool ok = false;

	int M = 998244353;
	int ans=1;

	

	for(int i=0;i<n;i++){
		if(deg[i]==0 || vis[i])continue;
		z=true;
		dfs(i);
		if(z){
			ok=true;
			ans*=2;
			ans%=M;
		}else{
			ok=false;
			break;
		}
	}

	if(!ok)ans=0;

	cout<<ans;
	

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