/*
	group : AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner Contest 222）
	name : A - Four Digits.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Four_Digits.cpp
	url : https://atcoder.jp/contests/abc222/tasks/abc222_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.10.2021 10:44:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x;
	cin>>x;

	string s = to_string(x);

	s="00000"+s;
	int n=s.size();

	for(int i=n-4;i<=n-1;i++)cout<<s[i];
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
//	parsed : 16-October-2021 10:44:07 IST