/*
	group : Codeforces - Codeforces Round #761 (Div. 2)
	name : C. Paprika and Permutation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Paprika_and_Permutation.cpp
	url : https://codeforces.com/contest/1617/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.12.2021 20:08:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	vector <bool> p(n+1);
	vector <int> bad;
	for(int x : v){
		cin>>x;
		if(x<=n && !p[x]){
			p[x]=true;
		}else{
			bad.push_back(x);
		}
	}
	int id=0;
	sort(bad.begin(),bad.end());
	for(int i=1;i<=n;i++){
		if(p[i])continue;
		if(2*i>=bad[id]){
			cout<<"-1\n";
			return;
		}
		id++;
	}
	cout<<id<<"\n";
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