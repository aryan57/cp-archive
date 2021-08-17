/*
	group : CodeChef - CodeChef Starters 9 Division 2 (Unrated)
	name : Black cells in a chessboard.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Black_cells_in_a_chessboard.cpp
	url : https://www.codechef.com/START9B/problems/BLACKCEL
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 20:00:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int ans=n*n;
	cout<<ans/2;
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
//	parsed : 17-August-2021 20:00:14 IST