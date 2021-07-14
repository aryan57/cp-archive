//https://codeforces.com/contest/1327/problem/B


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
 
void solve()
{
	int n,k,x,y,flag;
	cin>>n;
	int a[n+1],b[n+1]={},count=0;

	F(i,1,n)a[i]=1;

	F(i,1,n)
	{
		cin>>k;
		int g;

		flag=1;
		F(j,1,k)
		{
			cin>>g;
			if(a[g]) {
				if(flag){a[g]=0;b[i]=g;flag=0;
				}
				}

		}
		if(b[i])count++;
		else x=i;

		// F(i,1,n){
		// cout<<a[i]<<" ";
		// // if(a[i])y=i;
		// }nl;

		
	}

	F(i,1,n){
		// cout<<a[i]<<" ";
		if(a[i])y=i;
		}

	// cout<<"count "<<count<<" + "<<n;nl;

	if(count<n){
		cout<<"IMPROVE";nl;
		cout<<x<<" "<<y;nl;

	}
	else{
		cout<<"OPTIMAL";nl;
	}
}

signed main()
{
	#ifndef ONLINE_JUDGE
	freopen("11.txt", "r", stdin);
	#endif
	fast;

	int _t;
	cin>>_t;
	while(_t--)
	{
		solve();
	}

	return 0;
}