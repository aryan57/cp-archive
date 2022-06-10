/**
 *    author:  Aryan Agarwal
 *    created: 07.06.2022 20:21:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> s(n),f(n);
	for(int &x : s)cin>>x;
	for(int &x : f)cin>>x;

	int mx=0;
	for(int i=0;i<n;i++){
		mx=max(mx,s[i]);
		cout<<f[i]-mx<<" ";
		mx=max(mx,f[i]);
	}
	cout<<"\n";
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