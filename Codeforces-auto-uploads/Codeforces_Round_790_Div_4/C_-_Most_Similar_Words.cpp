/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 20:20:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf=  2e18;

void solve()
{
	int n,m;
	cin>>n>>m;
	vector <string> v(n);
	for(auto &s : v)cin>>s;

	int mn=inf;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int cost=0;
			for(int k=0;k<m;k++){
				cost+=abs(v[i][k]-v[j][k]);
			}
			mn=min(mn,cost);
		}
	}
	cout<<mn;
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