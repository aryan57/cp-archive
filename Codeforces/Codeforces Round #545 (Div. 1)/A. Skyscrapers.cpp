/*
	group : Codeforces - Codeforces Round #545 (Div. 1)
	name : A. Skyscrapers.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Skyscrapers.cpp
	url : https://codeforces.com/problemset/problem/1137/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.10.2021 11:16:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

/*
	previous mistake:-
	i assumed that the result of comparison of heights any two consecutive towers should not change
	but it is for any two towers in the same row or column, does not nedd to be consecutive
*/

void solve()
{
	int n,m;
	cin>>n>>m;
	int g[n][m];
	vector<vector<int>> row(n,vector<int> (m));
	vector<vector<int>> col(m,vector<int> (n));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			row[i][j]=g[i][j];
			col[j][i]=g[i][j];
		}
	}

	for(int i=0;i<n;i++){
		sort(row[i].begin(),row[i].end());
		auto it = unique(row[i].begin(),row[i].end());
		row[i].erase(it,row[i].end());
	}

	for(int j=0;j<m;j++){
		sort(col[j].begin(),col[j].end());
		auto it = unique(col[j].begin(),col[j].end());
		col[j].erase(it,col[j].end());
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			
			int id1 = lower_bound(row[i].begin(),row[i].end(),g[i][j])-row[i].begin();
			int id2 = lower_bound(col[j].begin(),col[j].end(),g[i][j])-col[j].begin();

			int rBig=row[i].size()-id1-1;
			int rSmall=id1;
			int cBig=col[j].size()-id2-1;
			int cSmall=id2;

			cout<< 1 + max(rBig,cBig) + max(rSmall,cSmall)<<" ";
		}
		cout<<"\n";
	}

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