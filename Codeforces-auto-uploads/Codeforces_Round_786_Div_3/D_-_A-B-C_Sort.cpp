/**
 *    author:  Aryan Agarwal
 *    created: 02.05.2022 20:52:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n),b(n);
	int ind=0;
	for(int &x : a){
		cin>>x;
		b[ind++]=x;
	}
	sort(b.begin(),b.end());
	for(int i=n-1;i>=1;i-=2){
		if((b[i]==a[i] && b[i-1]==a[i-1]) || (b[i]==a[i-1] && b[i-1]==a[i]))continue;
		cout<<"NO\n";
		return;
	}
	cout<<"YES\n";
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