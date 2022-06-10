/**
 *    author:  Aryan Agarwal
 *    created: 07.06.2022 20:23:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> pre(n+1);
	for(int i=1;i<=n;i++){
		char c;
		cin>>c;
		if(c=='B')pre[i]++;
		pre[i]+=pre[i-1];
	}
	int ans = n;
	for(int i=k;i<=n;i++){
		ans=min(ans,k-(pre[i]-pre[i-k]));
	}
	cout<<ans<<"\n";
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