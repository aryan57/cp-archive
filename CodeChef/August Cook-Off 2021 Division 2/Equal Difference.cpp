/*
	group : CodeChef - August Cook-Off 2021 Division 2
	name : Equal Difference.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Equal_Difference.cpp
	url : https://www.codechef.com/COOK132B/problems/EQDIFFER
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 21:36:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int mx=0;

	unordered_map<int,int> cnt;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;

		mx=max(mx,cnt[x]);
	}

	if(n<=2){
		cout<<0<<"\n";
		return;
	}
	int ans=n-mx;
	ans=min(ans,n-2);

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
//	parsed : 22-August-2021 21:30:10 IST