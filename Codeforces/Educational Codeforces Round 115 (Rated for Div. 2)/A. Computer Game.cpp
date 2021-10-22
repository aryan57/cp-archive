/*
	group : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
	name : A. Computer Game.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Computer_Game.cpp
	url : https://codeforces.com/contest/1598/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.10.2021 10:09:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <string> s(2);
	cin>>s[0]>>s[1];

	vector< vector<bool> > vis(2,vector <bool> (n,false));
	vis[0][0]=true;

	for(int j=0;j<n;j++){
		for(int i :{0,1}){
			if(!vis[i][j])continue;
			if(j+1<n && s[i][j+1]=='0')vis[i][j+1]=true;
			if(j+1<n && s[i^1][j+1]=='0')vis[i^1][j+1]=true;
		}
	}

	if(vis[1][n-1]){
		cout<<"YES\n";
	}else cout<<"NO\n";
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
//	parsed : 22-October-2021 10:08:09 IST