/**
 *    author:  Aryan Agarwal
 *    created: 15.02.2025 17:34:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n = s.size();
	int ans=0;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int k = 2*j - i;
			if(k>=n)break;

			if(s[i]=='A' && s[j]=='B' && s[k]=='C')ans++;
		}
	}

	cout<<ans;
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