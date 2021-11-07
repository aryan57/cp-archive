/*
	group : AtCoder - AtCoder Beginner Contest 226
	name : C - Martial artist.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Martial_artist.cpp
	url : https://atcoder.jp/contests/abc226/tasks/abc226_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 07.11.2021 17:39:01 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 2e5;
vector <int> adj[mxn+1];
vector <int> t(mxn+1);
vector <int> mn(mxn+1,-1);
vector <bool> use(mxn+1);

int dp(int i)
{
	if(mn[i]!=-1){
		return mn[i];
	}

	use[i]=true;

	for(int to : adj[i]){
		dp(to);
	}

	mn[i]=1;
	return 1;
}

void solve()
{
	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		int k;
		cin>>t[i]>>k;
		while (k--)
		{
			int a;
			cin>>a;
			adj[i].push_back(a);
		}
	}
	dp(n);

	int ans=0;
	for(int i=1;i<=n;i++){
		if(use[i])ans+=t[i];
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
//	parsed : 07-November-2021 17:35:57 IST