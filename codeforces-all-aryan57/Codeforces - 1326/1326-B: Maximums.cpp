//https://codeforces.com/contest/1326/problem/B

/*
	author : aryan57
*/
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
typedef long long int ll;
typedef unsigned long long ull;
 
#define int ll
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<"a[i]\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"
 
 
signed main()
{
	fast;

	int n;
	cin>>n;
	int b[n],x[n],a[n];

	cin>>b[0];
	x[0]=0;
	a[0]=b[0]+x[0];
	for(int i=1;i<n;i++)
	{
		cin>>b[i];
		x[i]=x[i-1];
		if(b[i-1]>0)x[i]+=b[i-1];
		a[i]=b[i]+x[i];
	}

	for(int i=0;i<n;i++)
	{
		cout<<a[i]<<" ";
	}

	

	return 0;
}