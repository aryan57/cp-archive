/*
	group : Codeforces - Educational Codeforces Round 120 (Rated for Div. 2)
	name : A. Construct a Rectangle.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Construct_a_Rectangle.cpp
	url : https://codeforces.com/contest/1622/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.12.2021 20:20:49 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	vector <int> v(3);
	for(int i=0;i<3;i++){
		cin>>v[i];
	}

	for(int i=0;i<3;i++){
		int x=v[(i-1+3)%3];
		int y=v[(i+1+3)%3];

		if((v[i]%2==0 && x==y) || x+y==v[i]){
			cout<<"YES\n";
			return;
		}
	}

	cout<<"NO\n";
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
//	parsed : 27-December-2021 20:20:10 IST