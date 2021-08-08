/*
	group : AtCoder - AtCoder Beginner Contest 213
	name : B - Booby Prize.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Booby_Prize.cpp
	url : https://atcoder.jp/contests/abc213/tasks/abc213_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.08.2021 17:31:50 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin >> n;
	vector<pair<int, int>> v(n);

	for (int i = 0; i < n; i++)
	{
		cin >> v[i].first;
		v[i].second = i+1;
	}

	sort(v.begin(),v.end());

	cout<<v[n-2].second<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while (_t--)
		solve();
	return 0;
}
//	parsed : 08-August-2021 17:30:58 IST