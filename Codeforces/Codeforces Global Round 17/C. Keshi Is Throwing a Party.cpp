/*
	group : Codeforces - Codeforces Global Round 17
	name : C. Keshi Is Throwing a Party.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Keshi_Is_Throwing_a_Party.cpp
	url : https://codeforces.com/contest/1610/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 24.11.2021 13:26:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int cnt=0;
	vector<pair<int,int> > v(n);
	for(pair <int,int> &p : v){
		cin>>p.first>>p.second;
	}

	int l=0;
	int r=n;
	int ans=0;

	while (l<=r)
	{
		int m=(l+r)/2;
		int c=0;
		for(int i=0;i<n;i++){
			if(m-1-v[i].first<=c && c<=v[i].second)c++;
		}

		if(c>=m){
			ans=max(ans,m);
			l=m+1;
		}else{
			r=m-1;
		}
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
//	parsed : 24-November-2021 13:26:44 IST