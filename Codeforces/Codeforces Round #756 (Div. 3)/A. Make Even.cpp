/*
	group : Codeforces - Codeforces Round #756 (Div. 3)
	name : A. Make Even.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Make_Even.cpp
	url : https://codeforces.com/contest/1611/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.11.2021 20:06:24 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	int n=stoi(s);
	if(n%2==0){
		cout<<0;
		cout<<"\n";
		return;
	}
	if((s[0]-'0')%2==0){
		cout<<1;
		cout<<"\n";
		return;
	}

	for(char x : s){
		if((x-'0')%2==0){
			cout<<2;
			cout<<"\n";
			return;
		}
	}

	cout<<"-1\n";

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
//	parsed : 25-November-2021 20:05:10 IST