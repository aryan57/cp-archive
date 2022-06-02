/**
 *    author:  Aryan Agarwal
 *    created: 10.01.2022 20:05:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	int mx = *max_element(v.begin(),v.end());
	int mn = *min_element(v.begin(),v.end());
	cout<<mx-mn;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 10-January-2022 20:05:11 IST