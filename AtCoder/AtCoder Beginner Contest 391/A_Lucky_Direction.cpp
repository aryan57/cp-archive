/**
 *    author:  Aryan Agarwal
 *    created: 01.02.2025 17:31:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	for(char &c : s){
		switch (c)
		{
		case 'N':
			c='S';
			break;
		case 'S':
			c='N';
			break;
		case 'E':
			c='W';
			break;
		case 'W':
			c='E';
			break;
		
		default:
			break;
		}
	}

	cout<<s;
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