/*
	group : Codeforces - Codeforces Round #765 (Div. 2)
	name : A. Ancient Civilization.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Ancient_Civilization.cpp
	url : https://codeforces.com/contest/1625/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.01.2022 17:39:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,l;
	cin>>n>>l;
	vector <int> v(n);
	for(int &x : v)cin>>x;
	int ans=0;

	for(int bit=0;bit<l;bit++){
		int cnt=0;
		for(int x : v){
			if((x>>bit)&1)cnt++;
		}
		if(cnt > n-cnt){
			ans+=(1<<bit);
		}
	}
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
//	parsed : 12-January-2022 17:39:23 IST