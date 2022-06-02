/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 11:43:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 2e18;

void solve()
{
	int n,m;
	cin>>n>>m;

	string s,t;
	cin>>s>>t;

	int ans=inf;

	vector<int> v;

	for(int i=0;i<=m-n;i++){
		int cnt=0;
		vector<int> tt;
		for(int j=0;j<n;j++){
			if(s[j]!=t[j+i]){
				cnt++;
				tt.push_back(j+1);
			}
		}
		if(ans>cnt){
			ans=cnt;
			v=tt;
		}
	}
	cout<<ans<<"\n";
	for(int x: v)cout<<x<<" ";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}