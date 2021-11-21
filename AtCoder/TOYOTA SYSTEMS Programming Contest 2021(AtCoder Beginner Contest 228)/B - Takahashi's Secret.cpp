/*
	group : AtCoder - TOYOTA SYSTEMS Programming Contest 2021(AtCoder Beginner Contest 228)
	name : B - Takahashi's Secret.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Takahashi_s_Secret.cpp
	url : https://atcoder.jp/contests/abc228/tasks/abc228_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.11.2021 10:31:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,x;
	cin>>n>>x;

	vector <int> adj[n+1];
	for(int i=1;i<=n;i++){
		int a;
		cin>>a;
		adj[i].push_back(a);
	}

	queue<int> q;
	vector<bool> visited(n+1);
	int cnt=1;
	
	q.push(x);
	visited[x] = true;
	
	while (!q.empty()) {
	
		int parent_node = q.front();
		q.pop();
	
		for (int child_node : adj[parent_node]) {
	
			if (!visited[child_node])
			{
				visited[child_node] = true;
				q.push(child_node);
				cnt++;
			}
		}
	}

	cout<<cnt;
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
//	parsed : 21-November-2021 10:31:40 IST