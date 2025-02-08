/**
 *    author:  Aryan Agarwal
 *    created: 08.02.2025 17:39:06 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> p(n+1),q(n+1),pos(n+1);
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		cin>>q[i];
		pos[q[i]]=i;
	}
	for(int i=1;i<=n;i++){
		int x = pos[i];
		int person = p[x];
		cout<<q[person]<<" ";
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