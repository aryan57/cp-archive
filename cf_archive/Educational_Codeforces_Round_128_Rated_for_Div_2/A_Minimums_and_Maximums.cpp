/**
 *    author:  Aryan Agarwal
 *    created: 13.05.2022 20:07:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int l1,r1,l2,r2;
	cin>>l1>>r1>>l2>>r2;

	if(max(l1,l2)<=min(r1,r2)){
		cout<<max(l1,l2)<<"\n";
	}else cout<<l1+l2<<"\n";
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