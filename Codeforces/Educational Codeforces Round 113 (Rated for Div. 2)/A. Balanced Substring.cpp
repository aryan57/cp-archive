/*
	group : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
	name : A. Balanced Substring.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Balanced_Substring.cpp
	url : https://codeforces.com/contest/1569/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.09.2021 20:26:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	string s;
	cin>>s;

	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]){
			cout<<i<<" "<<i+1<<"\n";
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
//	parsed : 08-September-2021 20:25:52 IST