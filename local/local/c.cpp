/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.12.2021 22:09:47 IST
 **/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> killProcess(vector<int> &pid, vector<int> &ppid, int kill)
{

	const int mxn = 5e4;
	vector<int> adj[mxn + 1];

	int n = pid.size();
	for (int i = 0; i < n; i++)
	{
		adj[ppid[i]].push_back(pid[i]);
	}

	vector<int> ans;

	function<void(int)> dfs = [&](int u) -> void
	{
		ans.push_back(u);
		for (int to : adj[u])
		{
			dfs(to);
		}
	};

	dfs(kill);

	return ans;
}

void solve()
{
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