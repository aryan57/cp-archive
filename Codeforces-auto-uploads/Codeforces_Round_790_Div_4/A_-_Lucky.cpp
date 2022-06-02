/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 20:15:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int s1=0;
	int s2=0;

	for(int i=0;i<3;i++)s1+=s[i]-'0';
	for(int i=3;i<6;i++)s2+=s[i]-'0';

	if(s1==s2)cout<<"YES\n";
	else cout<<"NO\n";

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