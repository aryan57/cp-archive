/*
	group : Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
	name : B. Coloring Rectangles.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Coloring_Rectangles.cpp
	url : https://codeforces.com/contest/1589/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.11.2021 11:45:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int n,int m)
{
	int ans = (n/3 + n%3)*m;
	int z=(n/3)*m + (n%3)*(m/3);
	if(n%3 || m%3){
		z++;
		if(n%3==2 && m%3==2)z++;

	}
	ans=min(ans,z);
	return ans;
}

void solve()
{
	int n,m;
	cin>>n>>m;

	int ans=f(n,m);
	ans=min(ans,f(m,n));

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
//	parsed : 14-November-2021 11:45:23 IST