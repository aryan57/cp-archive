/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 20:26:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n);
	int mn = 2e18;
	for(int i=0;i<n;i++){
		cin>>a[i];
		mn=min(mn,a[i]);
	}
	if(n%2){
		cout<<"Mike";
		cout<<"\n";
		return;
	}

	for(int i=0;i<n;i++){
		a[i]-=mn;
	}

	for(int i=0;;i++,i%=n){
		if(a[i]==0){
			if(i%2==0)cout<<"Joe\n";
			else cout<<"Mike\n";
			return;
		}
		a[i]--;

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