/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 17:30:55 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	string s="";
	for(int i=0;i<26;i++){
		s+=string(n,'A'+i);
	}
	k--;
	cout<<s[k];
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}