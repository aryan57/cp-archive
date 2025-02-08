/**
 *    author:  Aryan Agarwal
 *    created: 08.02.2025 17:31:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;

	if(a==b*c || b==c*a || c==a*b){
		cout<<"Yes";
	}else cout<<"No";
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