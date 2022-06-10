/**
 *    author:  Aryan Agarwal
 *    created: 07.06.2022 20:16:12 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int inf = 2e18;
	vector <int> a(n),b(n);
	for(int &x : a)cin>>x;
	for(int &x : b)cin>>x;

	int l=-inf;
	int r=inf;

	for(int i=0;i<n;i++){
		if(a[i]<b[i]){
			cout<<"NO\n";
			return;
		}
		if(b[i]==0){
			l=max(l,a[i]);
		}else{
			l=max(l,a[i]-b[i]);
			r=min(r,a[i]-b[i]);
		}
	}
	if(l>r)cout<<"NO\n";
	else cout<<"YES\n";
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