/*
	group : CodeChef - CodeChef Starters 9 Division 2 (Unrated)
	name : Large Square.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Large_Square.cpp
	url : https://www.codechef.com/START9B/problems/XLSQUARE
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 20:02:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,a;
	cin>>n>>a;

	int z=sqrt(n);

	int ans=a;

	for(int i=z-5;i<=z+5;i++){
		if(i*i<=n)ans=max(ans,i*a);
	}

	cout<<ans<<"\n";
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
//	parsed : 17-August-2021 20:00:48 IST