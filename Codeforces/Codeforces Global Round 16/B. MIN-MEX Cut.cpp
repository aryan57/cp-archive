/*
	group : Codeforces - Codeforces Global Round 16
	name : B. MIN-MEX Cut.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_MIN_MEX_Cut.cpp
	url : https://codeforces.com/contest/1566/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.09.2021 20:11:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;


	int cnt=0;
	int n=s.size();
	string z1(n,'1');
	string z0(n,'0');

	if(s==z1){
		cout<<0;
		cout<<"\n";
		return;
	}
	if(s==z0){
		cout<<1;
		cout<<"\n";
		return;
	}

	stack<int> z;

	for(char x : s)
	{
		if(z.empty())z.push(x-'0');
		else{
			if(z.top()!=x-'0')z.push(x-'0');
		}
	}

	if(z.size()>=4)cout<<2;
	else{
		if(z.size()<=2)cout<<1;

		else{
			if(z.top()==0)cout<<2;
			else cout<<1;
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
//	parsed : 12-September-2021 20:11:05 IST