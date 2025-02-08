/**
 *    author:  Aryan Agarwal
 *    created: 08.02.2025 17:33:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	int rem = n-m;
	vector<bool>vis(n+1);
	while (m--){
		int a;
		cin>>a;
		vis[a]=true;
	}
	cout<<rem<<"\n";
	for(int i=1;i<=n;i++){
		if(!vis[i])cout<<i<<" ";
	}
	
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