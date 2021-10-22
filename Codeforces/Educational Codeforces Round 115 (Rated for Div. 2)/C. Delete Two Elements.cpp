/*
	group : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
	name : C. Delete Two Elements.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Delete_Two_Elements.cpp
	url : https://codeforces.com/contest/1598/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.10.2021 10:23:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int s=0;
	vector<int> v(n);

	for(int &x : v){
		cin>>x;
		s+=x;
	}

	s*=2;
	if(s%n){
		cout<<"0\n";
		return;
	}
	s/=n;

	map<int,int> mp;
	int ans=0;
	for(int x : v){
		ans+=mp[s-x];
		mp[x]++;
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
//	parsed : 22-October-2021 10:21:26 IST