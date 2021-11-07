/*
	group : AtCoder - AtCoder Beginner Contest 226
	name : B - Counting Arrays.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Counting_Arrays.cpp
	url : https://atcoder.jp/contests/abc226/tasks/abc226_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 07.11.2021 17:34:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	set<string> s;

	while (n--)
	{
		int l;
		cin>>l;
		string z="";
		while (l--)
		{
			int x;
			cin>>x;
			z+=to_string(x);
			z+="$";
		}

		s.insert(z);
		
	}

	cout<<s.size();
	
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
//	parsed : 07-November-2021 17:33:46 IST