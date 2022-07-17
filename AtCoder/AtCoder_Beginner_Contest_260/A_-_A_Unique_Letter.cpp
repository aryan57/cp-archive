/**
 *    author:  Aryan Agarwal
 *    created: 17.07.2022 17:31:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	if(s[0]!=s[1] && s[0]!=s[2])cout<<s[0];
	else if(s[1]!=s[0] && s[1]!=s[2])cout<<s[1];
	else if(s[2]!=s[1] && s[2]!=s[0])cout<<s[2];
	else cout<<"-1\n";
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