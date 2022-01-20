/*
	group : Codeforces - Codeforces Round #765 (Div. 2)
	name : B. Elementary Particles.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Elementary_Particles.cpp
	url : https://codeforces.com/contest/1625/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.01.2022 17:51:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 150000;

void solve()
{
	int n;
	cin>>n;
	vector <int> pos[mxn+1];
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pos[x].push_back(i);
	}
	int ans=-1;
	for(int i=1;i<=mxn;i++){
		for(int j=1;j<pos[i].size();j++){
			ans=max(ans,n+pos[i][j-1]-pos[i][j]);
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
//	parsed : 12-January-2022 17:42:08 IST