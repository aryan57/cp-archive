/*
	group : CodeChef - October Lunchtime 2020 Division 1
	name : Chef Is Just Throwing Random Words.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Chef_Is_Just_Throwing_Random_Words.cpp
	url : https://www.codechef.com/LTIME89A/problems/SSO
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.08.2021 19:06:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<int> dp(50);

	while(n--){
		int x;
		cin>>x;

		int ind=0;
		while(x){
			dp[ind]+=x%2;
			x/=2;
			ind++;
		}
	}

	int ans=0;
	int pw=1;
	for(int i=0;i<50;i++,pw*=2){
		if(i>0)dp[i]+=dp[i-1]/2;
		if(dp[i])ans+=pw;
	}

	cout<<ans<<"\n";
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
//	parsed : 28-August-2021 19:06:47 IST