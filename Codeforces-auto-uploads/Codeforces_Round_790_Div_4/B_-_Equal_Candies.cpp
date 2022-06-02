/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 20:17:59 IST
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

	int mn=  *min_element(v.begin(),v.end());

	int x=0;
	for(int t : v){
		x+=t-mn;
	}
	cout<<x;
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