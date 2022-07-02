/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 17:31:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int k;
	cin>>k;

	int a=21;
	if(k>=60){
		a++;
		k-=60;
	}

	cout<<a<<":";
	if(k==0)cout<<"00";
	else if(k<10)cout<<"0"<<k;
	else cout<<k;
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