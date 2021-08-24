/*
	group : Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
	name : B. Charmed by the Game.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Charmed_by_the_Game.cpp
	url : https://codeforces.com/contest/1561/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 24.08.2021 20:28:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b;
	cin>>a>>b;

	int n=a+b;
	int o=(n+1)/2;
	int e=n-o;
	assert(e>=0);
	set<int> s;

	for(int k=0;k<=b;k++){

		bool ok = true;

		if(o-k>=0 && (e-(b-k))>=0){
			int z=k;
			z+=e-(b-k);
			s.insert(z);
			s.insert(n-z);
		}

	}

	cout<<s.size()<<"\n";
	for(int x : s)cout<<x<<" ";
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
//	parsed : 24-August-2021 20:12:11 IST