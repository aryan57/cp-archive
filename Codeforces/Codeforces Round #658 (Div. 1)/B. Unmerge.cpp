/*
	group : Codeforces - Codeforces Round #658 (Div. 1)
	name : B. Unmerge.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Unmerge.cpp
	url : https://codeforces.com/problemset/problem/1381/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 19:05:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<int> v(2*n+1);
	v[2*n]=2*n+1;

	for(int i=0;i<2*n;i++){
		cin>>v[i];
	}

	vector<int> z;
	z.push_back(0);

	int cur=1;
	int prev=v[0];

	for(int i=1;i<=2*n;i++){
		if(v[i]>prev){
			z.push_back(cur);
			cur=1;
			prev=v[i];
		}else{
			cur++;
		}
	}

	int k=z.size();
	k--;

	vector<vector<bool>> dp(k+1,vector<bool>(n+1));
	dp[0][0]=true;
	int ans=false;

	for(int i=1;i<=k;i++){
		for(int s=1;s<=n;s++){
			if(dp[i-1][s])dp[i][s]=true;
			else if(s>=z[i] && dp[i-1][s-z[i]])dp[i][s]=true;
		}
		if(dp[i][n]){
			ans=true;
			break;
		}
	}

	cout<< (ans ? "YES\n" : "NO\n");

	
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
//	parsed : 26-August-2021 18:47:15 IST