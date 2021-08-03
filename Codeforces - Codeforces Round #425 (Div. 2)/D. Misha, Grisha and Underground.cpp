/*
	group : Codeforces - Codeforces Round #425 (Div. 2)
	name : D. Misha, Grisha and Underground.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Misha_Grisha_and_Underground.cpp
	url : https://codeforces.com/contest/832/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.08.2021 13:49:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn=1e5;
vector<int> adj[mxn+1];
int T=0;
vector<int> tin(mxn+1),tout(mxn+1),depth(mxn+1);
const int mxbit=17;
int par[mxn+1][mxbit+1];

void dfs(int u,int p=0,int d=0){
	tin[u]=++T;
	depth[u]=d;
	par[u][0]=p;
	for(int v : adj[u]){
		if(v!=p)dfs(v,u,d+1);
	}
	tout[u]=++T;
}

bool is_ancestor(int v,int u){
	return tin[v]<=tin[u] && tout[u]<=tout[v];
}

int lca(int a,int b){
	if(is_ancestor(a,b))return a;
	if(is_ancestor(b,a))return b;

	for(int bit=0;bit<=mxbit;bit++){
		if(is_ancestor(par[a][bit],b)){
			assert(is_ancestor(par[a][bit],a));
			if(bit==0)return par[a][bit];
			return lca(par[a][bit-1],b);
		}
	}

	assert(false);
	return -1;
}

void fun(int a,int b,int c,int &ans)
{
	int z=lca(a,b);

	if(is_ancestor(z,c) && is_ancestor(c,a)){

		int dac=depth[a]-depth[c]+1;
		int dcb=depth[b]+depth[c]-2*depth[z]+1;

		ans=max(ans,dac);
		ans=max(ans,dcb);

	}
}

void solve()
{
	int n,q;
	cin>>n>>q;

	for(int i=2;i<=n;i++){
		int p;
		cin>>p;
		adj[p].push_back(i);
		adj[i].push_back(p);
	}

	dfs(1);

	for(int bit=1;bit<=mxbit;bit++){
		for(int i=1;i<=n;i++){
			if(par[i][bit-1]){
				par[i][bit]=par[par[i][bit-1]][bit-1];
			}
		}
	}

	while(q--){
		vector<int> v(3);
		cin>>v[0]>>v[1]>>v[2];

		int ans=0;

		do{
			int a=v[0];
			int b=v[1];
			int c=v[2];

			// if 'c' appears in path from 'a' to 'b'
			// ans will be max of dist(a,c) and dist(c,b)

			fun(a,b,c,ans);
			swap(a,b);
			fun(a,b,c,ans);

		}while(next_permutation(v.begin(),v.end()));

		cout<<ans<<"\n";

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
//	parsed : 03-August-2021 13:49:18 IST