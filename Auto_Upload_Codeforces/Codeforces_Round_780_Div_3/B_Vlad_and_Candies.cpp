/**
 *    author:  Aryan Agarwal
 *    created: 09.05.2022 10:48:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v)cin>>x;
	if(n==1){
		cout<<(v[0]==1?"YES\n":"NO\n");
		return;
	}
	sort(v.begin(),v.end(),greater<>());
	if(v[0]-v[1]<=1){
		cout<<"YES\n";
	}else cout<<"NO\n";
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