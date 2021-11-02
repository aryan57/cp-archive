/*
	group : Codeforces - Codeforces Round #753 (Div. 3)
	name : A. Linear Keyboard.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Linear_Keyboard.cpp
	url : https://codeforces.com/contest/1607/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 20:06:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int ans=0;
	int pos[26]={};
	string s;
	cin>>s;

	for(int i=0;i<26;i++){
		pos[s[i]-'a']=i;
	}

	cin>>s;

	int n=s.size();

	for(int i=1;i<n;i++){
		ans+=abs(pos[s[i]-'a']-pos[s[i-1]-'a']);
	}

	cout<<ans<<"\n";
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
//	parsed : 02-November-2021 20:05:18 IST