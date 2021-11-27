/*
	group : AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
	name : B - Hard Calculation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Hard_Calculation.cpp
	url : https://atcoder.jp/contests/abc229/tasks/abc229_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.11.2021 17:33:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s1,s2;
	cin>>s1>>s2;

	int k=s1.size()+s2.size();
	s1=string(k,'0')+s1;
	s2=string(k,'0')+s2;

	int carry=0;
	reverse(s1.begin(),s1.end());
	reverse(s2.begin(),s2.end());
	int i=0;
	while (i<s1.size() && i<s2.size())
	{
		int s=(s1[i]-'0') + (s2[i]-'0');
		if(s>=10){
			cout<<"Hard\n";
			return;
		}
		i++;
	}

	cout<<"Easy";
	
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
//	parsed : 27-November-2021 17:30:40 IST