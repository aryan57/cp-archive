/**
 *    author:  Aryan Agarwal
 *    created: 09.08.2021 20:09:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<int> v(n);
	int t=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		t+=v[i];
	}

	sort(v.begin(),v.end(),greater<int> ());

	t-=v[0];

	long double k= 1.0*t;
	k/=(n-1);
	k+=v[0];
	// cout<<ans<<" "<<c<<"\n";
	cout<<k<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout<<fixed<<setprecision(10);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 09-August-2021 20:05:27 IST