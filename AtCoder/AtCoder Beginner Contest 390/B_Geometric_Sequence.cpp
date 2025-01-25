/**
 *    author:  Aryan Agarwal
 *    created: 25.01.2025 17:33:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x : a)cin>>x;

	for(int i=1;i<n-1;i++){
		if(a[i]*a[i]!=a[i-1]*a[i+1]){
			cout<<"No\n";
			return;
		}
	}

	cout<<"Yes";
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