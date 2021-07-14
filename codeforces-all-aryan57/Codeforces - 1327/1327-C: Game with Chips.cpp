//https://codeforces.com/contest/1327/problem/C

/*
	author : aryan57
*/
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int PEG = 998244353;
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
	#ifndef ONLINE_JUDGE
	freopen("11.txt", "r", stdin);
	#endif
	fast;

	int n,m,k;
	cin>>n>>m>>k;

	int a,b;
	while(2*k--)cin>>a>>b;

	
	cout<<m-1+n-1+(m-1)*n+n-1;nl;
	F(i,1,m-1){cout<<"L";}
	F(i,1,n-1){cout<<"U";}

	F(i,1,n){
		if(i%2)F(j,1,m-1)cout<<"R";
		else F(j,1,m-1)cout<<"L";
		if(i!=n)cout<<"D";
	}
	return 0;

	
}