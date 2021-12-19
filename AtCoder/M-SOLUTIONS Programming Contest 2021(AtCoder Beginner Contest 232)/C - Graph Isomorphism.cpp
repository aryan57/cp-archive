/*
	group : AtCoder - M-SOLUTIONS Programming Contest 2021(AtCoder Beginner Contest 232)
	name : C - Graph Isomorphism.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Graph_Isomorphism.cpp
	url : https://atcoder.jp/contests/abc232/tasks/abc232_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 19.12.2021 17:36:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	bool g1[n+1][n+1]={},g2[n+1][n+1]={};

	for(int i=1;i<=m;i++){
		int a,b;
		cin>>a>>b;
		g1[a][b]=true;
		g1[b][a]=true;
	}
	for(int i=1;i<=m;i++){
		int c,d;
		cin>>c>>d;
		g2[c][d]=true;
		g2[d][c]=true;
	}

	vector <int> v(n);
	iota(v.begin(),v.end(),1);
	do
	{
		bool ok = true;
		for(int i=0;i<n;i++){
			for(int j=i+1;j<n;j++){
				if(g1[i+1][j+1]^g2[v[i]][v[j]]){
					ok=false;
					break;
				}
				if(!ok)break;
			}
		}
		if(ok){
			// for(int x : v)cout<<x<<" ";
			// cout<<"^\n";
			cout<<"Yes";
			return;
		}
	} while (next_permutation(v.begin(),v.end()));
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
//	parsed : 19-December-2021 17:34:02 IST