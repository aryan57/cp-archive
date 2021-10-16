/*
	group : AtCoder - Exawizards Programming Contest 2021（AtCoder Beginner Contest 222）
	name : C - Swiss-System Tournament.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Swiss_System_Tournament.cpp
	url : https://atcoder.jp/contests/abc222/tasks/abc222_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.10.2021 10:49:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector <int> win(101);

bool comp(int a,int b)
{
	assert(a!=b);
	if(win[a]!=win[b])return win[a]>win[b];
	return a<b;
}

void solve()
{
	int n,m;
	cin>>n>>m;

	vector <int> ranks(2*n);
	iota(ranks.begin(),ranks.end(),1);

	vector <string> a(2*n+1);

	for(int i=1;i<=2*n;i++){
		cin>>a[i];
		a[i]='#'+a[i];
	}

	for(int r=1;r<=m;r++)
	{
		for(int k=1;k<=n;k++){
			int p1=ranks[2*k-2];
			int p2=ranks[2*k-1];

			char s1=a[p1][r];
			char s2=a[p2][r];

			if(s1=='G' && s2=='C')win[p1]++;
			if(s2=='G' && s1=='C')win[p2]++;

			if(s1=='P' && s2=='G')win[p1]++;
			if(s2=='P' && s1=='G')win[p2]++;

			if(s1=='C' && s2=='P')win[p1]++;
			if(s2=='C' && s1=='P')win[p2]++;
		}

		sort(ranks.begin(),ranks.end(),comp);
	}

	for(int i=1;i<=2*n;i++){
		cout<<ranks[i-1]<<"\n";
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
//	parsed : 16-October-2021 10:46:55 IST