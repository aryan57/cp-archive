/*
	group : Codeforces - Educational Codeforces Round 68 (Rated for Div. 2)
	name : D. 1-2-K Game.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_1_2_K_Game.cpp
	url : https://codeforces.com/problemset/problem/1194/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 13:47:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	bool win=true;
	if(n<k || k%3){
		if(n%3==0)win=false;
	}else{

		int lambda = (n+1)/(k+1);
		if((n-lambda*(k+1))%3==0)win=false;
	}

	cout << (win ? "Alice\n" : "Bob\n");
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
//	parsed : 15-August-2021 12:52:31 IST