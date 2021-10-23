/*
	group : CodeChef - SnackDown 2021 - Online Round 1A
	name : Dance Moves.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Dance_Moves.cpp
	url : https://www.codechef.com/SNCK1A21/problems/DANCEMOVES
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 11:55:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x,y;
	cin>>x>>y;

	if(y<=x){
		cout<<x-y<<"\n";
		return;
	}
	if(abs(y-x)%2==0)cout<<(y-x)/2;
	else cout<<(y-x)/2+2;
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
//	parsed : 23-October-2021 11:55:52 IST