/**
 *    author:  Aryan Agarwal
 *    created: 13.11.2021 10:37:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;

	if(abs(a+c-2*b)%3)cout<<1;
	else cout<<0;
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
//	parsed : 13-November-2021 10:33:07 IST