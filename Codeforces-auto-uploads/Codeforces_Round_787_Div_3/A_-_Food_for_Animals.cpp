/**
 *    author:  Aryan Agarwal
 *    created: 05.05.2022 20:05:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c,x,y;
	cin>>a>>b>>c>>x>>y;

	x-=a;
	y-=b;

	x=max(x,0ll);
	y=max(y,0ll);

	if(c>=x+y)cout<<"YES\n";
	else cout<<"NO\n";
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