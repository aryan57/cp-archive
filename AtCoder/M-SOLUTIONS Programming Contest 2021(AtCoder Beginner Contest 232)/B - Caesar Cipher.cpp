/*
	group : AtCoder - M-SOLUTIONS Programming Contest 2021(AtCoder Beginner Contest 232)
	name : B - Caesar Cipher.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Caesar_Cipher.cpp
	url : https://atcoder.jp/contests/abc232/tasks/abc232_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 19.12.2021 17:32:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s,t;
	cin>>s>>t;
	set<int> k;
	int n=s.size();
	for(int i=0;i<n;i++){
		int z=(t[i]-s[i]+26)%26;
		k.insert(z);
	}

	if(k.size()==1)cout<<"Yes";
	else cout<<"No";
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
//	parsed : 19-December-2021 17:32:33 IST