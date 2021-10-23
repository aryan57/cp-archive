/*
	group : CodeChef - SnackDown 2021 - Online Round 1A
	name : Min Max LCM.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Min_Max_LCM.cpp
	url : https://www.codechef.com/SNCK1A21/problems/MINLCM1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 11:53:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x,k;
	cin>>x>>k;

	cout<<2*x<<" "<<(x*k*(x*k-1))<<"\n";
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
//	parsed : 23-October-2021 11:53:40 IST