/**
 *    author:  Aryan Agarwal
 *    created: 21.08.2021 16:15:55 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	
	vector<int> temp(n);
	iota(temp.begin(),temp.end(),1);
	set<int> rem(temp.begin(),temp.end());

	vector<set<int>> adj(n+1);
	vector<bool> vis(n+1,false);

	for(int i=1;i<=m;i++){

		int u,v;
		cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
	}

	int cnt=0;
	
	for(int i=1;i<=n;i++){
		if(vis[i])continue;
		cnt++;
		queue<int> q;
		q.push(i);
		vis[i]=true;
		auto it = rem.find(i);
		assert(it!=rem.end());
		rem.erase(it);

		while(!q.empty()){

			int p=q.front();
			q.pop();

			vector<int> temp;

			for(int t : rem){
				if(adj[p].find(t)==adj[p].end() && !vis[t]){
					vis[t]=true;
					q.push(t);
					temp.push_back(t);
				}
			}

			for(int t : temp){
				rem.erase(t);
			}
		}
	}

	cout<<cnt-1<<"\n";
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
//	parsed : 21-August-2021 16:11:14 IST