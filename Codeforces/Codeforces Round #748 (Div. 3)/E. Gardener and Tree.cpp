/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : E. Gardener and Tree.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Gardener_and_Tree.cpp
	url : https://codeforces.com/contest/1593/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.10.2021 20:37:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	if(n==1){
		cout<<0;
		cout<<"\n";
		return;
	}

	vector <int> deg(n);
	vector <set<int>> adj(n);
	priority_queue<pair <int,int> ,vector <pair <int,int> > ,greater<>> pq;

	for(int i=1;i<=n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].insert(v);
		adj[v].insert(u);
		deg[u]++;
		deg[v]++;
	}

	for(int i=0;i<n;i++){
		pq.push({deg[i],i});
	}

	int rem=n;

	while (k>0 && !pq.empty() && pq.top().first==1)
	{
		k--;
		priority_queue<pair <int,int> ,vector <pair <int,int> > ,greater<>> temp;

		while (!pq.empty() && pq.top().first==1)
		{
			int node=pq.top().second;
			pq.pop();

			rem--;

			if(adj[node].size()!=1)continue;

			int par = *adj[node].begin();

			deg[par]--;
			deg[node]--;

			adj[par].erase(node);
			adj[node].clear();

			if(deg[par]>=1)temp.push({deg[par],par});

		}

		pq.swap(temp);

	}

	cout<<rem<<"\n";
	
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
//	parsed : 14-October-2021 20:37:09 IST