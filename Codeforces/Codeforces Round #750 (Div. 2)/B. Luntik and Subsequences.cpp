/*
	group : Codeforces - Codeforces Round #750 (Div. 2)
	name : B. Luntik and Subsequences.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Luntik_and_Subsequences.cpp
	url : https://codeforces.com/contest/1582/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.10.2021 11:12:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> v(n);
	int c[2]={};
	for(int &x : v){
		cin>>x;
		if(x<=1)c[x]++;
	}

	int ans=(1ll<<c[0])*c[1];
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