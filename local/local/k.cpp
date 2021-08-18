/*
	group : local
	name : k.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/k.cpp
	url : /home/aryan/Desktop/cp-workspace/k.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 16:38:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n=10;
	cout<<(int)pow(2,n)<<"\n";

	for(int num=0;num<(int)pow(2,n);num++){
		cout<<n<<"\n";
		for(int bit=0;bit<n;bit++){
			if((num>>bit)&1)cout<<1;
			else cout<<0;
		}
		cout<<"\n";
	}
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