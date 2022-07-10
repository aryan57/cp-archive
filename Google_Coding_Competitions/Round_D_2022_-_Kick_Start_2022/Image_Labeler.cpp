/**
 *    author:  Aryan Agarwal
 *    created: 10.07.2022 10:36:51 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector <int> v(n);
	long double ans=0;
	for(int &x : v)cin>>x;
	sort(v.begin(),v.end());

	if((n-m+1)%2){
		ans+=v[(n-m+1)/2];
	}else if(((n-m+1)/2)-1>=0){
		long double zz=0;
		zz+=v[((n-m+1)/2)-1];
		zz+=v[(n-m+1)/2];
		zz/=2;
		ans+=zz;
	}

	for(int i=n-m+1;i<n;i++){
		ans+=v[i];
	}

	cout<<fixed<<setprecision(10)<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}