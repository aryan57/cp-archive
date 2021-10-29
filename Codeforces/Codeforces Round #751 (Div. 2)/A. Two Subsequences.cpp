/*
	group : Codeforces - Codeforces Round #751 (Div. 2)
	name : A. Two Subsequences.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Two_Subsequences.cpp
	url : https://codeforces.com/contest/1602/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.10.2021 19:54:50 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n = s.size();
	int cnt[26]={};

	for(int i=0;i<n;i++)
	{
		cnt[s[i]-'a']++;
	}

	for(int i=0;i<26;i++)
	{
		if(cnt[i]){
			cout<<char(i+'a')<<" ";
			cnt[i]--;
			break;
		}
	}
	
	for(int i=0;i<n;i++)
	{
		if(cnt[s[i]-'a']){
			cnt[s[i]-'a']--;
			cout<<s[i];
		}
	}
	cout<<"\n";
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
//	parsed : 29-October-2021 19:54:46 IST