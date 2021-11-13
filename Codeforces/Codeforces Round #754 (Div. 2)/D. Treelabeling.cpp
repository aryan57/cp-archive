/*
	group : Codeforces - Codeforces Round #754 (Div. 2)
	name : D. Treelabeling.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Treelabeling.cpp
	url : https://codeforces.com/contest/1605/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 13.11.2021 11:48:22 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int mxn = 2e5;
vector <int> black,white;
vector <int> adj[mxn+1];

void dfs(int u,int p,int parity){
	if(parity==0)white.push_back(u);
	else black.push_back(u);
	for(int to : adj[u]){
		if(to!=p)dfs(to,u,1^parity);
	}
}

void solve()
{
	int n;
	cin>>n;

	black.clear();
	white.clear();
	for(int i=0;i<=n;i++){
		adj[i].clear();
	}

	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	dfs(1,0,0);

	vector <int> ans(n+1,-1);
	vector <bool> used(n+1);
	int ind=0;
	int t=black.size();
	int t2=white.size();
	if(t>t2){
		swap(black,white);
		swap(t,t2);
	}

	for(int bit=0;bit<20;bit++){
		if((t>>bit)&1){
			int l=(1<<bit);
			int r=2*l-1;

			while (l<=r)
			{
				used[l]=true;
				ans[black[ind++]] = l++;
			}
			
		}
	}

	ind=0;

	for(int i=1;i<=n;i++){
		if(!used[i])ans[white[ind++]]=i;
	}

	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
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
//	parsed : 13-November-2021 11:48:13 IST