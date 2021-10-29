/*
	group : CodeChef - October Cook-Off 2021 Division 1
	name : Can You Reach The End.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Can_You_Reach_The_End.cpp
	url : https://www.codechef.com/COOK134A/problems/RECHEND
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.10.2021 09:25:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	for(pair <int,int> &p : v){
		cin>>p.first>>p.second;
	}
	sort(v.begin(),v.end());
	vector <pair <int,int> > adj[2*n];

	for(int i=0;i<n-1;i++){
		if(v[i].second<v[i+1].second){
			adj[2*i].push_back({2*i+2,v[i+1].second});
			adj[2*i+1].push_back({2*i+3,v[i+1].second});

			if(v[i].second+1<v[i+1].second)
			adj[2*i+1].push_back({2*i+2,v[i+1].second});
		}else{
			adj[2*i].push_back({2*i+2,v[i+1].second});
			adj[2*i+1].push_back({2*i+3,v[i+1].second});

			if(v[i].second-1>v[i+1].second)
			adj[2*i].push_back({2*i+3,v[i+1].second});
		}
	}

	queue<pair <int,pair <int,int> > > q;
	vector<bool> visited(2*n);
	
	q.push({0,{1,v[0].second-1}});
	visited[0] = true;

	while (!q.empty()) {
	
		auto parent_node = q.front();
		if(parent_node.first==2*n-1){
			cout<<"YES\n";
			return;
		}
		q.pop();
	
		for (auto child_node : adj[parent_node.first]) {
	
			if (!visited[child_node.first])
			{
				int l,r;
				if(child_node.first%2==0){
					l=1;
					r=child_node.second-1;
				}else{
					l=child_node.second+1;
					r=n;
				}
				l=max(l,parent_node.second.first);
				// r=min(r,parent_node.second.second);

				if(l<=r){
					visited[child_node.first] = true;
					q.push({child_node.first,{l,r}});
				}
			}
		}
	}

	cout<<"NO\n";

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
//	parsed : 27-October-2021 09:07:03 IST