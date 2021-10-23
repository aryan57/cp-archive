/*
	group : AtCoder - AtCoder Beginner Contest 224
	name : D - 8 Puzzle on Graph.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_8_Puzzle_on_Graph.cpp
	url : https://atcoder.jp/contests/abc224/tasks/abc224_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 17:55:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int m;
	cin>>m;

	vector <int> adj[10];
	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	string p(10,'0');
	for(int i=1;i<=8;i++){
		int x;
		cin>>x;
		p[x]=i+'0';
	}

	string t(10,'0');
	for(int i=1;i<=8;i++)t[i]=i+'0';

	queue<string > q;
	map<string,bool> visited;
	map<string,int> distance;
	
	q.push(p);
	visited[p] = true;
	distance[p]=0;


	while (!q.empty()) {
	
		auto parent_node = q.front();
		q.pop();

		int dv = distance[parent_node];

		if(parent_node==t){
			cout<<dv;
			return;
		}

		int pz=-1;

		for(int i=1;i<=9;i++){
			if(parent_node[i]=='0'){
				pz=i;
				break;
			}
		}
	
		for (int child_node : adj[pz]) {
			swap(parent_node[pz],parent_node[child_node]);
			if (!visited[parent_node])
			{
				visited[parent_node] = true;
				q.push(parent_node);
				distance[parent_node]=dv+1;
			}
			swap(parent_node[pz],parent_node[child_node]);
		}
	}

	cout<<"-1\n";
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
//	parsed : 23-October-2021 17:39:14 IST