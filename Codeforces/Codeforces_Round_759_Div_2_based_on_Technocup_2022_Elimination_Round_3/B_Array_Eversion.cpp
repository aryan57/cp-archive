/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 10:46:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	int mx = *max_element(v.begin(),v.end());
	if(v[n-1]==mx){
		cout<<"0\n";
		return;
	}

	int cnt=0;
	int cur=v[n-1];
	for(int i=n-2;i>=0;i--){
		if(v[i]<=cur)continue;
		cur=v[i];
		cnt++;
	}
	cout<<cnt<<"\n";
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