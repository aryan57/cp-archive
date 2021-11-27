/*
	group : AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
	name : C - Cheese.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Cheese.cpp
	url : https://atcoder.jp/contests/abc229/tasks/abc229_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.11.2021 17:37:33 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,w;
	cin>>n>>w;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end(),greater<>());
	int tot=0;
	for(int i=0;i<n;i++){
		int tk=min(w,v[i].second);
		tot+=tk*v[i].first;
		w-=tk;
	}
	cout<<tot;
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
//	parsed : 27-November-2021 17:30:40 IST