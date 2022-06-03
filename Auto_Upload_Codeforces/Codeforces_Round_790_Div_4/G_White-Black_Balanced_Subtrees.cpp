/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 20:45:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector< vector<int> > adj(n);
	vector <bool> black(n);
	for(int i=1;i<n;i++){
		int x;
		cin>>x;
		--x;
		adj[x].push_back(i);
		adj[i].push_back(x);
	}
	string s;
	cin>>s;
	for(int i=0;i<n;i++){
		if(s[i]=='B')black[i]=true;
	}
	int tot=0;

	function<pair<int,int>(int,int)> dfs = [&] (int u,int par)->pair<int,int> {
		pair<int,int> ans;
		if(black[u])ans.first++;
		else ans.second++;

		for(int to : adj[u]){
			if(to!=par){
				auto z = dfs(to,u);
				ans.first+=z.first;
				ans.second+=z.second;
			}
		}
		if(ans.first==ans.second)tot++;
		return ans;
	};

	dfs(0,-1);
	cout<<tot;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}