/**
 *    author:  Aryan Agarwal
 *    created: 19.06.2022 16:21:11 IST
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

	int q;
	cin>>q;
	while (q--){
		int t;
		cin>>t;

		vector <int> z(n);
		int cnt=0;
		bool ok = true;
		for(int i=0;i<n;i++){
			if(z[i]<v[i]){
				cnt++;
				z[i]+=t;
			}
			if(z[i]<v[i]){
				ok=false;
				break;
			}
			int extra = z[i]-v[i];
			if(i!=n-1){
				z[i+1]+=extra;
			}
		}
		if(!ok)cout<<"-1\n";
		else cout<<cnt<<"\n";
	}
	
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