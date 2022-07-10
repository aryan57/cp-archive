/**
 *    author:  Aryan Agarwal
 *    created: 09.07.2022 17:32:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m,x,t,d;
	cin>>n>>m>>x>>t>>d;

	vector <int> v(n+1,t);
	
	for(int i=min(n-1,x);i>=0;i--){
		v[i]=v[i+1]-d;
	}

	cout<<v[m];

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