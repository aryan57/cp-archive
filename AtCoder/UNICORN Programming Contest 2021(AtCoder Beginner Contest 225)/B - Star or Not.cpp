/*
	group : AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
	name : B - Star or Not.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Star_or_Not.cpp
	url : https://atcoder.jp/contests/abc225/tasks/abc225_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 17:32:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int cnt[n+1]={};

	for(int i=1;i<=n-1;i++){
		int u,v;
		cin>>u>>v;
		cnt[u]++;
		cnt[v]++;

		if(cnt[u]==n-1 || cnt[v]==n-1){
			cout<<"Yes";
			return;
		}
	}

	cout<<"No";
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
//	parsed : 30-October-2021 17:31:57 IST