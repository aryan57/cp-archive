/*
	group : Codeforces - Codeforces Round #130 (Div. 2)
	name : E. Blood Cousins.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Blood_Cousins.cpp
	url : https://codeforces.com/contest/208/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.08.2021 19:07:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long
const int mxbit=17;
const int mxn = 1e5;

int par[mxn+1][mxbit+1];
vector<int> adj[mxn+1],depth[mxn+1],depth_copy[mxn+1];
vector<int> tin(mxn+1),tout(mxn+1),depth_of(mxn+1);
int T=0;

void dfs(int u,int p,int d){
	par[u][0]=p;
	tin[u]=++T;
	depth[d].push_back(u);
	depth_copy[d].push_back(u);
	depth_of[u]=d;
	for(int v : adj[u])dfs(v,u,d+1);
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

bool is_ancestor(int a,int b){
	return tin[a]<=tin[b] && tout[b]<=tout[a];
}

int lca(int a,int b){
	if(is_ancestor(a,b))return a;
	if(is_ancestor(b,a))return b;

	for(int bit=0;bit<=mxbit;bit++){
		if(is_ancestor(par[a][bit],b)){
			assert(is_ancestor(par[a][bit],a));
			if(bit==0){
				return par[a][0];
			}
			return lca(par[a][bit-1],b);
		}
	}

	assert(false);
	return -1;
}

int kth_parent(int v,int k){
	int cur=v;
	for(int bit=mxbit;bit>=0;bit--){
		if((k>>bit)&1){
			cur=par[cur][bit];
			if(cur==0)break;
		}
	}
	return cur;
}

int children_at_d_depth(int v,int d){

	// for(int x : depth[d])cout<<x<<" ";cout<<"\n";
	// for(int x : depth[d])cout<<tin[x]<<" ";cout<<"\n";
	// cout<<v<<" "<<d<<"^\n";
	// cout<<tin[v]<<" "<<tout[v]<<"\n";
	// for(int x : depth_copy[d])cout<<x<<" ";cout<<"\n";
	// for(int x : depth_copy[d])cout<<tout[x]<<" ";cout<<"\n";

	int ind=lower_bound(depth[d].begin(),depth[d].end(),tin[v],
	[](const int& node,int time){
		return tin[node]<time;
	}) -depth[d].begin();

	int ind2=upper_bound(depth_copy[d].begin(),depth_copy[d].end(),tout[v],
	[](int time,const int& node){
		return time<tout[node];
	}) -depth_copy[d].begin();

	// cout<<ind<<" "<<ind2<<"&\n";

	assert(ind<=ind2);

	return ind2-ind;

}

bool comp1(int a,int b){
	return tin[a]<tin[b];
}
bool comp2(int a,int b){
	return tout[a]<tout[b];
}


void solve()
{
	int n;
	cin>>n;
	for(int i=1;i<=n;i++)
	{
		int p;
		cin>>p;
		adj[p].push_back(i);
	}

	dfs(0,0,0);
	preprocess(n);
	
	for(int i=0;i<=n;i++){
		sort(depth[i].begin(),depth[i].end(),comp1);
		sort(depth_copy[i].begin(),depth_copy[i].end(),comp2);
	}

	int q;
	cin>>q;
	while(q--){
		int v,k;
		cin>>v>>k;
		int p=kth_parent(v,k);
		if(p==0){
			cout<<0<<" ";
			continue;
		}
		// cout<<p<<"^\n";
		// i want to calculate no. of childern of node 'p' at depth same as of 'v'
		int tot=children_at_d_depth(p,depth_of[v]);
		cout<<tot-1<<" ";
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
//	parsed : 03-August-2021 19:07:36 IST