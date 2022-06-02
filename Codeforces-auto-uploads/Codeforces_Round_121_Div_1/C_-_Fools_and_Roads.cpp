/**
 *    author:  Aryan Agarwal
 *    created: 04.08.2021 12:40:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn=1e5;
const int mxbit=17;
int par[mxn+1][mxbit+1];
vector<pair<int,int>> adj[mxn+1];
vector<int> sum(mxn+1),tin(mxn+1),tout(mxn+1),adder(mxn+1);
int T=0;

void dfs(int u,int p){
	tin[u]=++T;
	par[u][0]=p;
	for(auto to : adj[u]){
		if(to.first!=p)dfs(to.first,u);
	}
	tout[u]=++T;
}

void preprocess(int n){
	for(int bit=1;bit<=mxbit;bit++){
		for(int i=1;i<=n;i++){
			if(par[i][bit-1]!=0){
				par[i][bit]=par[par[i][bit-1]][bit-1];
			}
		}
	}
}

// 0 is the dummy node
// parent of root
bool is_ancestor(int a,int b){
	if(a==0)return true;
	if(b==0)return false;
	return tin[a]<=tin[b] && tout[b]<=tout[a];
}

int lca(int a,int b){
	if(is_ancestor(a,b))return a;
	if(is_ancestor(b,a))return b;

	for(int bit=0;bit<=mxbit;bit++){
		if(is_ancestor(par[a][bit],b)){
			assert(is_ancestor(par[a][bit],a));
			if(bit==0)return par[a][0];
			return lca(par[a][bit-1],b);
		}
	}

	assert(false);
	return -1;
}

int dfs2(int u,int p){
	int tot=0;
	for(auto to : adj[u]){
		if(to.first==p)continue;
		int z=dfs2(to.first,u);
		sum[to.second]+=z;
		tot+=z;
	}
	tot+=adder[u];
	return tot;
}

void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
	}

	dfs(1,0);
	preprocess(n);

	int q;
	cin>>q;
	while(q--){
		int a,b;
		cin>>a>>b;
		int l=lca(a,b);
		adder[a]++;
		adder[b]++;
		adder[l]--;
		adder[l]--;
	}

	dfs2(1,0);

	for(int i=1;i<=n-1;i++)cout<<sum[i]<<" ";
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
//	parsed : 04-August-2021 12:40:11 IST