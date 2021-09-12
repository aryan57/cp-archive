/*
	group : Codeforces - Codeforces Global Round 16
	name : E. Buds Re-hanging.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Buds_Re_hanging.cpp
	url : https://codeforces.com/contest/1566/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.09.2021 22:12:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void dfs(int u,int p, vector <int> &par,vector <set<int> > &adj)
{
	par[u]=p;
	for(int to : adj[u])
	{
		if(to==p)continue;
		dfs(to,u,par,adj);
	}
}

bool is_bud(int i,vector <set<int> > &adj,vector <int> &par,vector <int> &deg)
{
	if(i==1)return false;

	bool ok = true;
	int zz=-1;

	for(int to : adj[i])
	{
		if(to==par[i])continue;
		zz=1;
		if(deg[to]!=1){
			ok=false;
			break;
		}
	}

	if(zz==-1){ // leaf node
		ok=false;
	}

	return ok;
}

void solve()
{
	int n;
	cin>>n;

	vector <int> deg(n+1);
	vector <int> par(n+1);
	vector <set<int> > adj(n+1);

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
		deg[u]++;
		deg[v]++;
	}

	dfs(1,-1,par,adj);

	int dena=0;
	int lena=0;

	set<int> buds;

	for(int i=1;i<=n;i++)if(is_bud(i,adj,par,deg))buds.insert(i);
	
	while (!buds.empty())
	{
		set<int> candidate_buds;

		for(int z : buds)
		{
			assert(z!=1);
			adj[par[z]].erase(z);
			adj[z].erase(par[z]);

			dena+=1;
			lena+=adj[z].size();
			
			deg[z]--;
			deg[par[z]]--;
			candidate_buds.insert(par[z]);
			if(par[par[z]]!=-1)candidate_buds.insert(par[par[z]]);
		}

		buds.clear();

		for(int i : candidate_buds)if(is_bud(i,adj,par,deg))buds.insert(i);

	}

	lena+=max(1ll,(int)adj[1].size());

	cout<<lena-dena;
	cout<<"\n";
	
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
//	parsed : 12-September-2021 21:58:15 IST