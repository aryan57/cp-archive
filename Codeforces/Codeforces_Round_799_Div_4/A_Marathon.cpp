/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:05:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c,d;
	cin>>a>>b>>c>>d;

	int cnt=0;
	if(b>a)cnt++;
	if(c>a)cnt++;
	if(d>a)cnt++;
	cout<<cnt;
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