/*
	group : Codeforces - Codeforces Round #482 (Div. 2)
	name : C. Kuro and Walking Route.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Kuro_and_Walking_Route.cpp
	url : https://codeforces.com/contest/979/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 11:33:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 3e5;

vector <int> adj[mxn+1];
int n,x,y;
int sx,sy;

int dfs(int u,int par)
{
	int s=1;
	for(int to : adj[u])
	{
		if(to!=par)
		{
			s+=dfs(to,u);
		}
	}
	if(s!=n){
		if(u==x)sx=s;
		if(u==y)sy=s;
	}
	return s;
}

void solve()
{
	cin>>n>>x>>y;

	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(x,-1);
	dfs(y,-1);
	// cout<<sx<<" "<<sy<<"^\n";
	cout<<n*(n-1) - sx*sy;
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
//	parsed : 15-October-2021 11:14:10 IST