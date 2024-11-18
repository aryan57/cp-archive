/**
 *    author:  Aryan Agarwal
 *    created: 17.11.2024 20:06:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	vector<int> cnt(n+1);
	int ans=0;

	for(int i=0;i<n;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}

	for(int i=1;i<=n;i++){
		ans+=cnt[i]/2;
	}

	cout<<ans;cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}