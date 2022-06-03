/**
 *    author:  Aryan Agarwal
 *    created: 15.05.2022 22:59:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(m));
	vector<vector<int>> cur(n,vector<int>(m));
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			g[i][j]=s[j]-'0';
		}
	}
	if(g[0][0]){
		cout<<"-1\n";
		return;
	}
	vector<vector<int>> ans;

	for(int i=0;i<n;i++){
		for(int j=m-1;j>0;j--){
			if(cur[i][j]==g[i][j])continue;
			assert(cur[i][j]==0);
			ans.push_back({i+1,j,i+1,j+1});
			cur[i][j]=1;
		}
	}
	for(int i=n-1;i>0;i--){
		if(cur[i][0]==g[i][0])continue;
		assert(cur[i][0]==0);
		ans.push_back({i,1,i+1,1});
		cur[i][0]=1;
	}

	assert(ans.size()<=n*m);
	cout<<ans.size()<<"\n";
	for(auto v : ans){
		for(int x : v)cout<<x<<" ";
		cout<<"\n";
	}
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