/**
 *    author:  Aryan Agarwal
 *    created: 15.02.2025 17:31:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s1,s2;
	cin>>s1>>s2;

	if(s1=="sick" && s2=="fine"){
		cout<<2;
	}
	else if(s1=="fine" && s2=="sick"){
		cout<<3;
	}
	else if(s1=="fine" && s2=="fine"){
		cout<<4;
	}
	else if(s1=="sick" && s2=="sick"){
		cout<<1;
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}