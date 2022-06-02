/**
 *    author:  Aryan Agarwal
 *    created: 05.05.2022 20:26:49 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 2e5;
vector< vector<int> > paths;
vector <int> parent(mxn+1);
vector <int> max_dep(mxn+1);

vector <int> adj[mxn+1];

int n;

int dfs_dep(int u){
	max_dep[u]=1;
	for(int to : adj[u]){
		if(to==parent[u])continue;
		max_dep[u]=max(max_dep[u],1+dfs_dep(to));
	}
	return max_dep[u];
}

void dfs(int u,vector <int> &path){
	path.push_back(u);
	if(max_dep[u]==1){
		paths.push_back(path);
		return;
	}
	int mxid=-1;
	int mxval=0;
	for(int to : adj[u]){
		if(to==parent[u])continue;
		if(mxval<max_dep[to]){
			mxval=max_dep[to];
			mxid=to;
		}
	}
	assert(mxid!=-1);
	dfs(mxid,path);
	for(int to : adj[u]){
		if(to==parent[u] || to==mxid)continue;
		vector <int> path;
		dfs(to,path);
	}

}

void solve()
{
	cin>>n;
	int root=-1;
	paths.clear();
	for(int i=1;i<=n;i++){
		adj[i].clear();
	}
	for(int i=1;i<=n;i++){
		cin>>parent[i];
		if(i==parent[i])root=i;
		else{
			adj[i].push_back(parent[i]);
			adj[parent[i]].push_back(i);
		}
		max_dep[i]=0;
	}
	dfs_dep(root);
	vector <int> path;
	dfs(root,path);
	cout<<paths.size();
	cout<<"\n";
	for(auto v : paths){
		cout<<v.size();
		cout<<"\n";
		for(int x : v){
			cout<<x<<" ";
		}
		cout<<"\n";
	}
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