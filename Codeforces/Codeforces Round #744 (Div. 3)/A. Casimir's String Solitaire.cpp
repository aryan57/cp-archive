/*
	group : Codeforces - Codeforces Round #744 (Div. 3)
	name : A. Casimir's String Solitaire.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Casimir_s_String_Solitaire.cpp
	url : https://codeforces.com/contest/1579/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.09.2021 20:07:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int c[3]={};

	for(char x : s)
	{
		c[x-'A']++;
	}

	cout<<(c[1]==c[0]+c[2]?"YES\n":"NO\n");
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