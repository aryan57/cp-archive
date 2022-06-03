/**
 *    author:  Aryan Agarwal
 *    created: 08.05.2022 20:07:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n);
	int cnt=0;
	for(int &x : a){
		cin>>x;
		if(x==0)cnt++;
	}

	if(cnt){
		cout<<n-cnt;
		cout<<"\n";
		return;
	}

	sort(a.begin(),a.end());

	for(int i=1;i<n;i++){
		if(a[i]==a[i-1]){
			cout<<n;
			cout<<"\n";
			return;
		}
	}
	cout<<n+1;
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