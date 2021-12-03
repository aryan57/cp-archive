/*
	group : AtCoder - AtCoder Beginner Contest 230
	name : D - Destroyer Takahashi.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Destroyer_Takahashi.cpp
	url : https://atcoder.jp/contests/abc230/tasks/abc230_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.12.2021 18:37:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,d;
	cin>>n>>d;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}

	sort(v.begin(),v.end(),[](pair <int,int> a,pair <int,int> b){
		return a.second<b.second;
	});

	int mx=0;
	int cnt=0;
	for(int i=0;i<n;i++){
		if(mx>=v[i].first)continue;
		mx=v[i].second+d-1;
		cnt++;
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
//	parsed : 03-December-2021 18:03:20 IST