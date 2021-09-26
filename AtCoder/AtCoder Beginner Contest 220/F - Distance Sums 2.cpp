/*
	group : AtCoder - AtCoder Beginner Contest 220
	name : F - Distance Sums 2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Distance_Sums_2.cpp
	url : https://atcoder.jp/contests/abc220/tasks/abc220_f
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.09.2021 00:05:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn = 2e5;
vector <int> adj[mxn+1];
vector <int> depth(mxn+1);
vector <int> child(mxn+1);
vector <int> ans(mxn+1);
int sum=0;
int n;
int dfs(int u,int p,int d)
{
	depth[u]=d;
	sum+=d;
	child[u]=1;
	for(int to : adj[u])
	{
		if(to==p)continue;
		child[u]+=dfs(to,u,d+1);
	}
	return child[u];
}
void dfs2(int u,int p)
{
	if(u==1){
		ans[u]=sum;
	}else{
		assert(p>0);
		ans[u]=n-2*child[u]+ans[p];
	}
	for(int to : adj[u])
	{
		if(to==p)continue;
		dfs2(to,u);
	}
}

void solve()
{
	
	cin>>n;

	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,0,0);
	dfs2(1,0);

	for(int i=1;i<=n;i++){
		cout<<ans[i]<<"\n";
	}
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