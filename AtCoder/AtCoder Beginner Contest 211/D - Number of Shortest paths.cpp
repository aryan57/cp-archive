/*
	group : AtCoder - AtCoder Beginner Contest 211
	name : D - Number of Shortest paths.cpp
	srcPath : /home/aryan/cp-gedit/D_Number_of_Shortest_paths.cpp
	url : https://atcoder.jp/contests/abc211/tasks/abc211_d
*/
#include <bits/stdc++.h>
using namespace std;
const int32_t M = 1e9 + 7;
const int32_t inf = 1e9;

#define int long long

signed main()
{
    int n,m;
	cin>>n>>m;
	
	vector<int> adj[n+1];
	
	for(int i=1;i<=m;i++) {
		int a,b;
		cin>>a>>b;
		adj[a].push_back(b);
		adj[b].push_back(a);
	}
	
	queue<int> q;
	vector<bool> vis(n+1,false);
	vector<int> d(n+1,inf);
	vis[1]=true;
	q.push(1);
	d[1]=0;
	
	vector<int> dp(n+1,0);
	dp[1]=1;
	
	while(!q.empty()) {
		int p=q.front();
		q.pop();
		
		for(auto c : adj[p]) {
			if(vis[c]) {
				if(d[c]==d[p]+1) {
					dp[c]+=dp[p];
					dp[c]%=M;
				}
				
				continue;
			}
			
			q.push(c);
			d[c] = d[p] + 1;
			dp[c]=dp[p];
			vis[c]=true;
			
		}
	}
	
	cout<<dp[n];
    return 0;
}
//	parsed : 24-July-2021 19:44:15 IST