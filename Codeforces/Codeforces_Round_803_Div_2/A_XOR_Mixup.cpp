/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 03:05:52 IST
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

	for(int i=0;i<n;i++){
		int tot=0;
		for(int j=0;j<n;j++){
			if(j==i)continue;
			tot^=v[j];
		}
		if(tot==v[i]){
			cout<<v[i];
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