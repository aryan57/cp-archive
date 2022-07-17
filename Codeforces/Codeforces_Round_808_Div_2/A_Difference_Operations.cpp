/**
 *    author:  Aryan Agarwal
 *    created: 16.07.2022 20:14:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n);
	for(int &x : a)cin>>x;

	for(int i=1;i<n;i++){
		if(a[i]%a[0]){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
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