/*
	group : AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner Contest 222）
	name : B - Failing Grade.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Failing_Grade.cpp
	url : https://atcoder.jp/contests/abc222/tasks/abc222_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.10.2021 10:46:16 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,p;
	cin>>n>>p;

	int cnt=0;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x<p)cnt++;
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
//	parsed : 16-October-2021 10:45:55 IST