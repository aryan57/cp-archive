/*
	group : Codeforces - Codeforces Round #572 (Div. 1)
	name : A1. Add on a Tree.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A1_Add_on_a_Tree.cpp
	url : https://codeforces.com/problemset/problem/1188/A1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 15:18:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<int> adj[n];
	vector<int> deg(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		deg[u]++;
		deg[v]++;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	for(int i=0;i<n;i++){
		if(adj[i].size()==2 && deg[i]!=1){
			cout<<"NO\n";
			return;
		}
	}

	cout<<"YES\n";
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
//	parsed : 15-August-2021 14:56:44 IST