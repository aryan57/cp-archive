/*
	group : Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
	name : A. Regular Bracket Sequences.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Regular_Bracket_Sequences.cpp
	url : https://codeforces.com/contest/1574/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.09.2021 20:06:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<"(";
			if(i==j)cout<<")";
		}
		for(int j=1;j<=n-1;j++)
		{
			cout<<")";
		}
		cout<<"\n";
	}
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
//	parsed : 20-September-2021 20:05:20 IST