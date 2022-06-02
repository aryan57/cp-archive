/**
 *    author:  Aryan Agarwal
 *    created: 13.05.2022 16:58:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,a,b;
	cin>>n>>a>>b;
	vector<int> v(n);
	for(int &x : v)cin>>x;

	v.insert(v.begin(),0);

	int mn = 2e18;

	int tot=v[n];
	int cnt=1;

	for(int i=n-1;i>=0;i--){
		mn = min(mn,(a+b)*v[i]+b*(tot-cnt*v[i]));
		tot+=v[i];
		cnt++;
	}

	cout<<mn<<"\n";
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