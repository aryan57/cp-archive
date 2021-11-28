/*
	group : Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
	name : A. Distance.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Distance.cpp
	url : https://codeforces.com/problemset/problem/1612/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.11.2021 19:33:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x,y;
	cin>>x>>y;
	if((x+y)%2){
		cout<<"-1 -1\n";
		return;
	}
	int t=(x+y)/2;
	for(int a=0;a<=t;a++){
		int b=t-a;
		if(abs(a-x)+abs(b-y)==t){
			cout<<a<<" "<<b<<"\n";
			return;
		}
	}
	cout<<"-1 -1\n";
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
//	parsed : 28-November-2021 19:33:23 IST