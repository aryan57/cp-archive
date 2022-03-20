/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/cp-workspace/c.cpp
	url : /home/aryan/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 10:34:01 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n=15;
	for(int i=0;i<n;i++){
		int r=rand()%3;
		if(r==2)cout<<'?';
		else cout<<r;
	}
	cout<<"\n";
}

signed main()
{
freopen("input.txt","w",stdout);
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=100;
	// cin>>_t;

	cout<<_t<<"\n";
	
// freopen("input.txt","r",stdin);
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}