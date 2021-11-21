/*
	group : AtCoder - TOYOTA SYSTEMS Programming Contest 2021(AtCoder Beginner Contest 228)
	name : C - Final Day.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Final_Day.cpp
	url : https://atcoder.jp/contests/abc228/tasks/abc228_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.11.2021 10:38:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<pair<int,int> > v(n);

	for(int i=0;i<n;i++){
		int x=0;
		int s=0;
		for(int j=0;j<3;j++){
			cin>>x;
			s+=x;
		}
		v[i]={s,i};
	}

	sort(v.begin(),v.end());

	vector <bool> ans(n);

	for(int i=0;i<n;i++){
		pair <int,int> p = {v[i].first+300,n+1};
		int it = upper_bound(v.begin(),v.end(),p)-v.begin();
		// cout<<it<<"^\n";
		if(n-it+1<=k)ans[v[i].second]=true;
	}

	for(int i=0;i<n;i++)cout<< (ans[i] ? "Yes\n" : "No\n");
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
//	parsed : 21-November-2021 10:37:33 IST