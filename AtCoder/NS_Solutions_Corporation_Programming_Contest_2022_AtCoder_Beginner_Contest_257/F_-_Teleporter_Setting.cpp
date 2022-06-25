/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 18:20:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int inf = 1e9;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector <vector <int> > adj(n);
	vector <bool> star(n);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		if(u==-1){
			star[v]=true;
		}else{
			adj[u].push_back(v);
			adj[v].push_back(u);
		}
	}

	auto bfs = [&](int s)->vector<int>{
		vector<int> d(n,inf);
		d[s]=0;
		queue<int> q;
		q.push(s);
		while (!q.empty())
		{
			int u=q.front();
			q.pop();
			for(int to : adj[u]){
				if(d[to]==inf){
					d[to]=d[u]+1;
					q.push(to);
				}
			}
		}
		return d;
	};

	const vector <int> &d1 = bfs(0);
	const vector <int> &d2 = bfs(n-1);

	int d1s=inf;
	int d2s=inf;

	for(int i=0;i<n;i++){
		if(star[i]){
			d1s=min(d1s,d1[i]);
			d2s=min(d2s,d2[i]);
		}
	}

	for(int i=0;i<n;i++){
		int ans = d1[n-1];
		ans=min(ans,min(d1s+1,d1[i])+min(d2s+1,d2[i]));
		if(ans==inf)ans=-1;
		cout<<ans<<" ";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}