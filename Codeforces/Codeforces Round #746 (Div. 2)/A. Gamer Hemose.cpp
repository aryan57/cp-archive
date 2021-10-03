/*
	group : Codeforces - Codeforces Round #746 (Div. 2)
	name : A. Gamer Hemose.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Gamer_Hemose.cpp
	url : https://codeforces.ml/contest/1592/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.10.2021 20:14:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,h;
	cin>>n>>h;

	vector <int> v(n);
	for(int &x : v)cin>>x;

	sort(v.begin(),v.end(),greater<> ());

	int z=h/(v[0]+v[1]);
	int ans=2*z;
	h-=(v[0]+v[1])*z;

	if(h>0){
		h-=v[0];
		ans++;
	}
	if(h>0){
		h-=v[1];
		ans++;
	}

	assert(h<=0);

	cout<<ans;
	cout<<"\n";
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
//	parsed : 03-October-2021 20:12:36 IST