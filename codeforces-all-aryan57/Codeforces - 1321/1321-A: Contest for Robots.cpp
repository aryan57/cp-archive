//https://codeforces.com/contest/1321/problem/A

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
#define crap freopen("input.txt","r",stdin)
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define nl cout<<"\n"


signed main()
{
	#ifndef ONLINE_JUDGE 
  
    /* For getting input from input.txt file*/ 
    freopen("input.txt", "r", stdin); 
  
    // Printing the Output to output.txt file 
    // freopen("output.txt", "w", stdout); 
  
	#endif
	fast;

	int n,flag=0,countr=0,countb=0;
	cin>>n;

	int r[n+1],b[n+1];
	in1(r, n);in1(b, n);

	F(i, 1, n)
	{
		if(r[i]!=b[i])
		{
			if(r[i])countr++;
			if(b[i])countb++;
			flag=1;
		}
	}
	
	
		

	if(flag==0 || countr==0) cout<<"-1";
	else if(countr)cout<<countb/countr +1;

	return 0;
}