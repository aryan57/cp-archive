/*
	group : Codeforces - Codeforces Round #425 (Div. 2)
	name : D. Misha, Grisha and Underground.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Misha_Grisha_and_Underground.cpp
	url : https://codeforces.com/contest/832/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 04.08.2021 17:27:13 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long
const int mxn=1e5;
const int mxbit=17;
int par[mxn+1][mxbit+1];
vector<int> adj[mxn+1],tin(mxn+1),tout(mxn+1),depth(mxn+1);
int T=0;

void dfs(int u,int p,int d){
	tin[u]=++T;
	depth[u]=d;
	par[u][0]=p;
	for(int bit=1;bit<=mxbit;bit++){
		if(par[u][bit-1]!=0){
			par[u][bit]=par[par[u][bit-1]][bit-1];
		}
	}
	for(int to : adj[u]){
		if(to!=p)dfs(to,u,d+1);
	}
	tout[u]=++T;
}


bool is_ancestor(int a,int b){
	return tin[a]<=tin[b] && tout[b]<=tout[a];
}

// lca of node 'a' and 'b' considering '1' as root
int lca(int a,int b){
	if(is_ancestor(a,b))return a;
	if(is_ancestor(b,a))return b;

	for(int bit=mxbit;bit>=0;bit--){
		if(!is_ancestor(par[a][bit],b)){
			a=par[a][bit];
		}
	}
	
	return par[a][0];
}

int dist(int a,int b){
	int l=lca(a,b);
	return depth[a]+depth[b]-2*depth[l];
}

// lca of node 'a' and 'b' considering 'r' as root
int lca(int a,int b,int r){
	int x=lca(a,b);
	int y=lca(a,r);
	int z=lca(b,r);

	/*
		atleast two of the lca's in 3c2 pairs, must be equal,
		https://stackoverflow.com/questions/25371865/find-multiple-lcas-in-unrooted-tree
	*/

	if(x==y)return z;
	if(x==z)return y;
	if(y==z)return x;

	assert(false);
	return -1;
}

int cal(int u,int v,int r){

	int t=lca(u,v,r);
	return dist(t,r);
}

void solve()
{
	int n,q;
	cin>>n>>q;

	for(int i=2;i<=n;i++){
		int p;
		cin>>p;
		adj[i].push_back(p);
		adj[p].push_back(i);
	}
	adj[0].push_back(1);
	dfs(0,0,0);
	while(q--){
		int a,b,c;
		cin>>a>>b>>c;

		int ans=0;
		ans=max(ans,cal(a,b,c));
		ans=max(ans,cal(a,c,b));
		ans=max(ans,cal(c,b,a));

		cout<<ans+1<<"\n";
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
//	parsed : 04-August-2021 17:26:50 IST