/**
 *    author:  Aryan Agarwal
 *    created: 12.06.2022 20:13:12 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;
	vector <int> a(n);
	for(int &x : a)cin>>x;
	sort(a.begin(),a.end());
	vector <int> pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+a[i-1];

	while (q--)
	{
		int x,y;
		cin>>x>>y;
		cout<<pre[n-x+y]-pre[n-x]<<"\n";
	}
	
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