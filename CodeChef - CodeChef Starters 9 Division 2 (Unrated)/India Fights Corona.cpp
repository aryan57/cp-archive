/*
	group : CodeChef - CodeChef Starters 9 Division 2 (Unrated)
	name : India Fights Corona.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/India_Fights_Corona.cpp
	url : https://www.codechef.com/START9B/problems/CORONA
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 20:55:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;
void solve()
{
	int n,m,k;
	cin>>n>>m>>k;

	vector<pair<int,int>> adj[n+1];

	for(int i=1;i<=k;i++){
		int x,C;
		cin>>x>>C;

		adj[0].push_back({x,C});
		adj[x].push_back({0,C});
	}

	for(int i=1;i<=m;i++){
		int u,v,w;
		cin>>u>>v>>w;

		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
	}

	vector<int> d(n+1,INF);

	d[0] = 0;
	using pii = pair<int, int>;
	priority_queue<pii, vector<pii>, greater<pii>> q;
	q.push({0, 0});
	while (!q.empty()) {
		int v = q.top().second;
		int d_v = q.top().first;
		q.pop();
		if (d_v != d[v])
			continue;

		for (auto edge : adj[v]) {
			int to = edge.first;
			int len = edge.second;

			if (d[v] + len < d[to]) {
				/*
					q.erase({d[to], to});

					no need to erase, let the old pair be in the priority_queue,
					since we are always accessing the smallest pair,
					this old pair will never be used.
				*/
				d[to] = d[v] + len;

				q.push({d[to], to});
			}
		}
	}

	for(int i=1;i<=n;i++){
		cout<<d[i]<<" ";
	}cout<<"\n";
	
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
//	parsed : 17-August-2021 20:51:32 IST