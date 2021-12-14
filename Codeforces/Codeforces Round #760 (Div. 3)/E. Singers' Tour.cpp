/*
	group : Codeforces - Codeforces Round #760 (Div. 3)
	name : E. Singers' Tour.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Singers_Tour.cpp
	url : https://codeforces.com/contest/1618/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.12.2021 21:36:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> b(n),c(n);
	for(int &x : b)cin>>x;

	if(n==1){
		cout<<"YES\n";
		cout<<b[0]<<"\n";
		return;
	}

	c[0]=b[0]-b[n-1];
	int sc=c[0];
	int r=(c[0]%n+n)%n;
	int mx=r;
	mx=max(mx,n+c[0]);
	for(int i=1;i<n;i++){
		c[i]=b[i]-b[i-1];
		sc+=c[i];
		mx=max(mx,n+c[i]);
		if((c[i]%n+n)%n!=r){
			cout<<"NO\n";
			return;
		}
	}
	if(sc){
		cout<<"NO\n";
		return;
	}
	int lem = (mx-r+n-1)/n;
	int s=lem*n+r;
	int sum=0;
	vector <int> a(n);
	for(int i=0;i<n;i++){
		assert(s-c[i]>0);
		assert((s-c[i])%n==0);
		a[i]=(s-c[i])/n;
		sum+=a[i];
	}
	assert(sum==s);
	cout<<"YES\n";
	for(int x : a)cout<<x<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 14-December-2021 21:12:03 IST