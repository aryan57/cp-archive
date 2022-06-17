/**
 *    author:  Aryan Agarwal
 *    created: 17.06.2022 08:35:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n),a(n);
	for(int &x : a)cin>>x;

	if(n==1){
		if(!a[0])cout<<"YES\n";
		else cout<<"NO\n";
		return;
	}
	
	while (n>=1)
	{
		if(a[n-1]==0)n--;
		else break;
	}

	if(n==0){
		cout<<"YES\n";
		return;
	}
	if(n==1){
		cout<<"NO\n";
		return;
	}
	
	for(int i=0;i<=n-3;i++)v[i]=1;

	for(int i=n-2;i>=0;i--){
		if(v[i+1]<a[i+1]){
			cout<<"NO\n";
			return;
		}
		int req=v[i+1]-a[i+1];
		v[i]+=req;
		if(i)v[i]--;
		v[i+1]=a[i+1];
	}

	if(v[0]==a[0]){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
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