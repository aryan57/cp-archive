/**
 *    author:  Aryan Agarwal
 *    created: 19.06.2022 14:39:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	int ans=(m*(m+1))/2;
	int cur=2*m;
	while (cur<=n*m)
	{
		ans+=cur;
		cur+=m;
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
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}