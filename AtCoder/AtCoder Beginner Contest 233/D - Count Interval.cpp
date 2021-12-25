/*
	group : AtCoder - AtCoder Beginner Contest 233
	name : D - Count Interval.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Count_Interval.cpp
	url : https://atcoder.jp/contests/abc233/tasks/abc233_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.12.2021 17:49:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	int cnt=0;
	int pre=0;
	map<int,int> mp;
	mp[pre]++;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		pre+=x;
		cnt+=mp[pre-k];
		mp[pre]++;
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
//	parsed : 25-December-2021 17:43:39 IST