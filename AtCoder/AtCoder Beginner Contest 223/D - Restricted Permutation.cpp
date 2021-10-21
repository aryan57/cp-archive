/*
	group : AtCoder - AtCoder Beginner Contest 223
	name : D - Restricted Permutation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Restricted_Permutation.cpp
	url : https://atcoder.jp/contests/abc223/tasks/abc223_d
*/
#include <bits/stdc++.h>
using namespace std;

const int mxn = 2e5;
vector<int> adj[mxn];

vector<int> topological_sort(int n)
{
	vector<int> in_degree(n,0);

	for (int i=0;i<n;i++)
		for(int to : adj[i])
			in_degree[to]++;
	
	priority_queue<int,vector<int>,greater<>> pq;

	for (int i = 0; i < n; i++)
		if (in_degree[i] == 0)
			pq.push(i);

	int cnt = 0;
	vector<int> top_order;

	while (!pq.empty()) {

		int u = pq.top();
		pq.pop();
		top_order.push_back(u);
		cnt++;

		for (auto to : adj[u])
			if (--in_degree[to] == 0)
				pq.push(to);
	}

	if (cnt != n)return {-1};
	
	return top_order;
}

int main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	int n,m;
	cin>>n>>m;
	while (m--)
	{
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
	}
	
	vector<int> topo_sort = topological_sort(n);

	if(topo_sort[0]==-1){
		cout<<"-1\n";
		return 0;
	}

	for(int x : topo_sort)cout<<x+1<<" ";
	return 0;
}
