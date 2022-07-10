/**
 *    author:  Aryan Agarwal
 *    created: 10.07.2022 13:09:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn = 1e5 + 1;
vector< vector<int> > adj(mxn);
set<int> s;
int n,m,k;
bool dfs(int i){
	s.insert(i);
	if(s.size()>k)return true;

	for(int to : adj[i]){
		if(s.find(to)==s.end()){
			s.insert(to);
			if(s.size()>k)return true;
			if(dfs(to))return true;
		}
	}
	return false;
}

void solve()
{
	cin>>n>>m>>k;

	for(int i=0;i<n;i++){
		adj[i].clear();
	}

	for(int i=0;i<m;i++){
		int a,b;
		cin>>a>>b;
		--a;--b;
		// adj[a].push_back(b);
		adj[b].push_back(a);
	}
	int ans=0;
	int cnt=0;

	for(int i=0;i<n;i++){
		s.clear();
		if(dfs(i))ans++;
	}

	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}