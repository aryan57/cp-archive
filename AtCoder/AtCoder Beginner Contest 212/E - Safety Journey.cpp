/*
	group : AtCoder - AtCoder Beginner Contest 212
	name : E - Safety Journey.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Safety_Journey.cpp
	url : https://atcoder.jp/contests/abc212/tasks/abc212_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 10:56:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int M=998244353;

	int n,m,k;
	cin>>n>>m>>k;

	vector<int> adj[n];
	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	vector<int> dp(n);
	dp[0]=1;
	while(k--){

		int s=0;
		for(int x : dp){
			s+=x;
			s%=M;
		}

		vector<int> val(n);

		for(int i=0;i<n;i++){

			val[i]=s;
			val[i]-=dp[i];
			val[i]%=M;

			for(int to : adj[i]){
				val[i]-=dp[to];
				val[i]%=M;
			}

			val[i]+=M;
			val[i]%=M;

		}
		for(int i=0;i<n;i++)dp[i]=val[i];

	}

	cout<<dp[0];
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
//	parsed : 15-August-2021 09:28:18 IST