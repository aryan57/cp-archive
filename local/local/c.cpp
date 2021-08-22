/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 21:27:46 IST
**/
#include <bits/stdc++.h>
#include <sys/resource.h>
using namespace std;

#define int long long

void solve()
{
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	rlimit R;
	getrlimit(RLIMIT_STACK, &R);
	R.rlim_cur = R.rlim_max;
	setrlimit(RLIMIT_STACK, &R);

	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}