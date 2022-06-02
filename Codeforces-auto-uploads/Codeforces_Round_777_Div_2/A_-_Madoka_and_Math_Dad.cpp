/**
 *    author:  Aryan Agarwal
 *    created: 15.05.2022 22:36:10 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	string x="";
	int z=2;
	if(n%3==1){
		z=1;
	}

	while(n>0){
		x+='0'+z;
		n-=z;
		z^=2^1;
	}
	cout<<x<<"\n";
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