/**
 *    author:  Aryan Agarwal
 *    created: 12.06.2022 20:08:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector <int> a(n);
	for(int &x : a)cin>>x;

	int cur=m;
	int tot=0;
	for(int i=0;i<n;i++){
		if(a[i]<=cur){
			cur-=a[i];
		}else{
			tot+=a[i]-cur;
			cur=0;
		}
	}
	cout<<tot<<"\n";
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