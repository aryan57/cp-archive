/**
 *    author:  Aryan Agarwal
 *    created: 17.06.2022 08:20:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	int ans=1;
	for(int i=1;i<n;i++){
		ans+=(s[i]==s[i-1]?1:i+1);
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}