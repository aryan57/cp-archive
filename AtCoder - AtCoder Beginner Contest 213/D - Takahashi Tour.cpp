/*
	group : AtCoder - AtCoder Beginner Contest 213
	name : D - Takahashi Tour.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Takahashi_Tour.cpp
	url : https://atcoder.jp/contests/abc213/tasks/abc213_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.08.2021 17:43:33 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int mxn = 2e5;
vector<int> adj[mxn + 1];
vector<bool> vis(mxn + 1);
int n;
// stack<int> s;
void dfs(int u,int p=0)
{
	cout << u << " ";
	// s.push(u);

	// vis[u] = true;
	// bool ok = false;

	for (int to : adj[u])
	{
		if(to==p)continue;
		dfs(to,u);
		cout << u << " ";
	}

	// int last=-1;
	// if(!ok)
	// {
	// 	s.pop();
	// 	while(!s.empty()){
	// 		last=s.top();
	// 		s.pop();
	// 		if(!s.empty())cout<<last<<" ";
	// 	}

	// 	if(last!=-1){
	// 		dfs(last);
	// 	}
	// }
}

void solve()
{
	cin >> n;

	for (int i = 1; i <= n - 1; i++)
	{
		int u, v;
		cin >> u >> v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	for (int i = 1; i <= n; i++)
	{
		sort(adj[i].begin(), adj[i].end());
	}
	// adj[0].push_back(1);
	dfs(1);
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while (_t--)
		solve();
	return 0;
}
//	parsed : 08-August-2021 17:41:32 IST