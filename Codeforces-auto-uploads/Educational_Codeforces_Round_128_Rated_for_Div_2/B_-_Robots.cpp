/**
 *    author:  Aryan Agarwal
 *    created: 13.05.2022 20:11:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	int g[n][m]={};
	vector<pair<int,int>> v;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			if(s[j]=='R'){
				g[i][j]=1;
				v.push_back({i,j});
			}
		}
	}
	int k=v.size();
	for(int i=0;i<k;i++){
		bool ok = true;
		for(int j=0;j<k;j++){
			if(v[j].first-v[i].first<0 || v[j].second-v[i].second<0){
				ok=false;
				break;
			}
		}
		if(ok){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
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