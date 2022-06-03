/**
 *    author:  Aryan Agarwal
 *    created: 09.05.2022 10:45:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b;
	cin>>a>>b;

	if(a==0){
		cout<<1;
	}else{
		cout<<a+2*b+1;
	}
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