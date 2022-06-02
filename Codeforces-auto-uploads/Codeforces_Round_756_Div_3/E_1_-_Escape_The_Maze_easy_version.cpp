/**
 *    author:  Aryan Agarwal
 *    created: 26.11.2021 09:16:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int mxn = 2e5;
const int INF = 2e9;
vector <int> adj[mxn+1];
vector <int> height(mxn+1),d(mxn+1),val(mxn+1);
vector <bool> x(mxn+1);
vector <bool> good(mxn+1);
bool ok;

void dfs1(int u,int h,int par){
	height[u]=h;
	for(int to : adj[u]){
		if(to!=par)dfs1(to,h+1,u);
	}
}

int dfs2(int u,int par){
	int mn=d[u];
	for(int to : adj[u]){
		if(to!=par)mn=min(mn,dfs2(to,u));
	}
	if(2*height[u]<mn)good[u]=true;
	return mn;
}

void dfs3(int u,int par){
	if(!good[u] || ok)return;
	bool leaf=true;
	for(int to : adj[u]){
		if(to!=par){
			leaf=false;
			dfs3(to,u);
		}
	}
	if(leaf)ok=true;
}

void solve()
{
	int n,k;
	cin>>n>>k;

	for(int i=1;i<=n;i++){
		adj[i].clear();
		d[i]=0;
		val[i]=0;
		height[i]=0;
		x[i]=false;
		good[i]=false;
	}
	ok=false;

	for(int i=1;i<=k;i++){
		int u;
		cin>>u;
		x[u]=true;
	}

	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs1(1,0,0);

	for(int i=1;i<=n;i++){
		if(x[i])d[i]=height[i];
		else d[i]=INF;
	}

	dfs2(1,0);
	dfs3(1,0);
	if(ok)cout<<"YES\n";
	else cout<<"NO\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}