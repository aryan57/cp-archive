/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 03:11:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	if(k==1){
		cout<<(n-1)/2;
		cout<<"\n";
		return;
	}

	int cnt=0;
	for(int i=1;i+1<n;i++){
		if(v[i]>v[i-1]+v[i+1])cnt++;
	}
	cout<<cnt;
	cout<<"\n";
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