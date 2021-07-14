//https://codeforces.com/contest/1311/problem/A

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
	// crap; //to be COMMENTED later
	fast;

	int t,a,b;
	cin>>t;

	while(t--)
	{
		cin>>a>>b;
		if(a>b){if((b-a)%2==0)cout<<"1\n";
		else cout<<"2\n";}

		if(a<b){if((a-b)%2==0)cout<<"2\n";
		else cout<<"1\n";}

		if(a==b)
		{
			cout<<"0\n";
		}
		
	}

	return 0;
}