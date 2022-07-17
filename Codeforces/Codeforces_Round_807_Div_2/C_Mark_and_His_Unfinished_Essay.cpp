/**
 *    author:  Aryan Agarwal
 *    created: 16.07.2022 07:59:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int k=654156494;
	string s = bitset<32>(k).to_string();
	cout<<s;
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