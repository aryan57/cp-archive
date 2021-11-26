/*
	group : Codeforces - Codeforces Round #757 (Div. 2)
	name : A. Divan and a Store.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Divan_and_a_Store.cpp
	url : https://codeforces.com/contest/1614/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.11.2021 16:46:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,l,r,k;
	cin>>n>>l>>r>>k;

	vector <int> v;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>=l && x<=r)v.push_back(x);
	}

	sort(v.begin(),v.end());
	int cnt=0;

	for(int x : v){
		if(k-x>=0){
			k-=x;
			cnt++;
		}
	}

	cout<<cnt<<"\n";
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
//	parsed : 26-November-2021 16:45:08 IST