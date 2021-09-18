/*
	group : AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest 219）
	name : A - AtCoder Quiz 2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_AtCoder_Quiz_2.cpp
	url : https://atcoder.jp/contests/abc219/tasks/abc219_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.09.2021 17:30:51 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	if(n>=90){
		cout<<"expert";
		return;
	}

	if(n>=70){
		cout<<90-n;
	}else if(n>=40){
		cout<<70-n;

	}else if(n>=0){
		cout<<40-n;

	}
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
//	parsed : 18-September-2021 17:30:10 IST