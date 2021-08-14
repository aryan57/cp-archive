/*
	group : AtCoder - AtCoder Beginner Contest 214
	name : F - Substrings.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Substrings.cpp
	url : https://atcoder.jp/contests/abc214/tasks/abc214_f
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.08.2021 20:04:22 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n=s.size();

	int M = 1e9+7;
	vector<int> dp(n+2);
	int ans=0;
	dp[0]=1;
	for(int i=0;i<n;i++){

		for(int j=i;j>=0;j--){

			dp[i+2]+=dp[j];
			dp[i+2]%=M;

			if(j-1>=0 && s[j-1]==s[i])break;

		}

		ans+=dp[i+2];
		ans%=M;
	}

	cout<<ans;
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
//	parsed : 14-August-2021 19:32:24 IST