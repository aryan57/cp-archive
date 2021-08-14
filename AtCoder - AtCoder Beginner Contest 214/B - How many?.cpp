/*
	group : AtCoder - AtCoder Beginner Contest 214
	name : B - How many?.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_How_many_.cpp
	url : https://atcoder.jp/contests/abc214/tasks/abc214_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.08.2021 17:32:06 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int s,t;
	cin>>s>>t;

	int cnt=0;

	for(int i=0;i<=s;i++){
		
		for(int j=0;j<=s;j++){
			if(i+j>s)break;
			// if(i*j>t)break;
			for(int k=0;k<=s;k++){
				if(i+j+k>s)break;
				if(i*j*k>t)break;
				cnt++;
			}

		}
	}

	cout<<cnt;
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
//	parsed : 14-August-2021 17:31:40 IST