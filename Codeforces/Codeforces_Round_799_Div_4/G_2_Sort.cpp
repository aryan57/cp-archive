/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:38:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> a(n);
	for(int &x : a)cin>>x;

	int cnt=0;
	int l=1;

	for(int i=1;i<n;i++){
		if(a[i-1]<2*a[i]){
			l++;
		}else{
			if(l>=k+1)cnt+=l-k;
			l=1;
		}
	}
	if(l>=k+1)cnt+=l-k;
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