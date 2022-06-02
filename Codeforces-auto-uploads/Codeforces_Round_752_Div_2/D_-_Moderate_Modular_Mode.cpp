/**
 *    author:  Aryan Agarwal
 *    created: 31.10.2021 09:13:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x,y;
	cin>>x>>y;

	if(x==y){
		cout<<x;
	}else if(x>y){
		cout<<x+y;
	}else{
		cout<<x*(y/x)+(y%x)/2;
	}
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 31-October-2021 09:13:51 IST