/**
 *    author:  Aryan Agarwal
 *    created: 04.07.2022 20:07:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	if(n%2)cout<<"-1\n";
	else {

	cout<<n/2<<" "<<0<<" "<<n/2;
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