/*
	group : CodeChef - SnackDown 2021 - Online Round 1A
	name : Round Robin Ranks .cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Round_Robin_Ranks_.cpp
	url : https://www.codechef.com/SNCK1A21/problems/RRR
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 10:37:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	cout<<2*(n-k + (k-1)/2)<<"\n";
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
//	parsed : 23-October-2021 10:37:11 IST