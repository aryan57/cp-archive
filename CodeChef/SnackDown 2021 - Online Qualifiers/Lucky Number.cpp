/*
	group : CodeChef - SnackDown 2021 - Online Qualifiers
	name : Lucky Number.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Lucky_Number.cpp
	url : https://www.codechef.com/SNCKQL21/problems/LUCKYNUM
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 22:31:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;

	if(a==7 || b==7 || c==7)cout<<"YES\n";
	else cout<<"NO\n";
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
//	parsed : 15-October-2021 22:30:59 IST