/*
	group : AtCoder - KEYENCE Programming Contest 2021 (AtCoder Beginner Contest 227)
	name : B - KEYENCE building.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_KEYENCE_building.cpp
	url : https://atcoder.jp/contests/abc227/tasks/abc227_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 13.11.2021 17:35:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	set<int> s;

	for(int a=1;;a++){
		if(4*a*1+3*a+3*1 > 1000)break;
		for(int b=1;;b++){
			if(4*a*b+3*a+3*b > 1000)break;
			s.insert(4*a*b+3*a+3*b);

		}
	}

	int n;
	cin>>n;
	int cnt=0;
	while (n--)
	{
		int x;
		cin>>x;

		if(s.find(x)==s.end())cnt++;
	}

	cout<<cnt;
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 13-November-2021 17:35:26 IST