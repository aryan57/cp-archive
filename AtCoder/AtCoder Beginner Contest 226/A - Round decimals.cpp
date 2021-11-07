/*
	group : AtCoder - AtCoder Beginner Contest 226
	name : A - Round decimals.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Round_decimals.cpp
	url : https://atcoder.jp/contests/abc226/tasks/abc226_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 07.11.2021 17:30:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string x;
	cin>>x;

	int ind=-1;
	int n=x.size();
	int zz=0;
	for(int i=0;i<n;i++){

		if(x[i]=='.'){
			if(i<n-1 && x[i+1]>='5'){
				zz++;
			}
			break;
		}else{
			zz*=10;
			zz+=x[i]-'0';
		}
	}

	cout<<zz;
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
//	parsed : 07-November-2021 17:30:12 IST