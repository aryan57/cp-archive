/*
	group : Codeforces - Codeforces Round #738 (Div. 2)
	name : A. Mocha and Math.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Mocha_and_Math.cpp
	url : https://codeforces.com/contest/1559/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 20:07:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int ans;
	cin>>ans;

	for(int i=1;i<n;i++){
		int k;
		cin>>k;
		ans&=k;
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
//	parsed : 15-August-2021 20:05:05 IST