/**
 *    author:  Aryan Agarwal
 *    created: 01.03.2025 17:32:55 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		if(i && a[i]<=a[i-1]){
			cout<<"No\n";
			return;
		}
	}

	cout<<"Yes\n";
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