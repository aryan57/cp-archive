/*
	group : Codeforces - Hello 2022
	name : A. Stable Arrangement of Rooks.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Stable_Arrangement_of_Rooks.cpp
	url : https://codeforces.com/contest/1621/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.01.2022 20:43:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> t;
	int i=1;
	while (k--)
	{
		if(i>n){
			cout<<"-1\n";
			return;
		}
		t.push_back(i-1);
		i+=2;
	}

	vector< vector<char> > g(n,vector <char> (n,'.'));
	for(int x : t){
		g[x][x]='R';
	}
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++)cout<<g[i][j];
		cout<<"\n";
	}
	
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
//	parsed : 03-January-2022 20:05:48 IST