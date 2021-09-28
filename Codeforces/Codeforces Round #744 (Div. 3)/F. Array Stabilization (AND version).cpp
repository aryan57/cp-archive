/*
	group : Codeforces - Codeforces Round #744 (Div. 3)
	name : F. Array Stabilization (AND version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Array_Stabilization_AND_version_.cpp
	url : https://codeforces.com/contest/1579/problem/F
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.09.2021 21:56:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,d;
	cin>>n>>d;

	vector <int> v(n);
	vector< vector<int> > adj(n);
	queue<int> q;
	vector<bool> visited(n);
	vector<int> distance(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		int tt=(i+n-d+n)%n;
		adj[tt].push_back(i);
		if(v[i]==0){
			q.push(i);
			visited[i]=true;
		}
	}

	
	while (!q.empty()) {
	
		int parent_node = q.front();
		q.pop();
	
		for (int child_node : adj[parent_node]) {
	
			if (!visited[child_node])
			{
				visited[child_node] = true;
				q.push(child_node);
				distance[child_node] = distance[parent_node] + 1;
			}
		}
	}
	int ans=0;
	for(int i=0;i<n;i++){
		if(!visited[i]){
			cout<<"-1\n";
			return;
		}

		ans=max(ans,distance[i]);
	}

	cout<<ans;
	cout<<"\n";
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
//	parsed : 28-September-2021 21:56:38 IST