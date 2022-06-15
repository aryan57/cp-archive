/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:14:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n=8;
	vector <string> g(n);
	for(int i=0;i<n;i++){
		cin>>g[i];
	}

	for(int i=1;i<n-1;i++){
		for(int j=1;j<n-1;j++){
			if(g[i][j]!='#')continue;
			if(g[i-1][j-1]!='#')continue;
			if(g[i-1][j+1]!='#')continue;
			if(g[i+1][j-1]!='#')continue;
			if(g[i+1][j+1]!='#')continue;
			cout<<i+1<<" "<<j+1;
			cout<<"\n";
			return;
		}
	}
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