/*
	group : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
	name : B. Groups.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Groups.cpp
	url : https://codeforces.com/contest/1598/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.10.2021 10:15:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;

	int m=5;

	vector< vector<int> > v(n,vector <int> (m));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>v[i][j];
		}
	}

	for(int x=0;x<m;x++){
		for(int y=x+1;y<m;y++){

			int cx=0;
			int cy=0;
			int cxy=0;

			for(int i=0;i<n;i++){
				if(v[i][x] && v[i][y])cxy++;
				else if(v[i][x])cx++;
				else if(v[i][y])cy++;
			}

			int k=n/2;

			int req=max(0,k-cx);
			if(req>cxy)continue;
			cxy-=req;

			req=max(0,k-cy);
			if(req>cxy)continue;
			cxy-=req;

			cout<<"YES\n";
			return;
		}
	}

	cout<<"NO\n";
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
//	parsed : 22-October-2021 10:13:14 IST