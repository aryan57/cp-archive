/*
	group : AtCoder - UNICORN Programming Contest 2021(AtCoder Beginner Contest 225)
	name : C - Calendar Validator.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Calendar_Validator.cpp
	url : https://atcoder.jp/contests/abc225/tasks/abc225_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 17:34:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector< vector<int> > b(n,vector <int> (m));
	vector< vector<int> > a(n,vector <int> (7));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>b[i][j];
		}
	}


	for(int st=0;st<=7-m;st++){

		int t=b[0][0]-st;
		if(t<0 || t%7!=1)continue;

		int r1=t/7;

		for(int i=0;i<n;i++){
			for(int j=0;j<7;j++){
				a[i][j]=t++;
			}
		}

		bool ok = true;

		for(int i=0;i<n;i++){
			for(int j=0;j<m;j++){
				if(a[i][j+st]!=b[i][j]){
					ok=false;
					break;
				}
			}
		}

		if(ok){
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
//	parsed : 30-October-2021 17:34:05 IST