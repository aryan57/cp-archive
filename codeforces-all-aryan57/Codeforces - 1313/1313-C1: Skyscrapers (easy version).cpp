//https://codeforces.com/contest/1313/problem/C1

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

	int n;
	cin>>n;
	int m[n],temp[n];

	in(m,n);
	
	int k,minsum,maxindex,sum,maxval,min=*min_element(m,m+n);

	// F(i,0,n-1)cout<<m[i]<<" ";

	F(i,0,n-1)
	{
		
		temp[i]=m[i];
		// for(temp[i]=m[i];temp[i]>=min;temp[i]--)
		// {
			sum=0;
			F(j,i+1,n-1)
			{
				temp[j]=m[j];
				if(temp[j]>temp[j-1])
				{
					sum+=temp[j]-temp[j-1];
					temp[j]=temp[j-1];
				}
			}
			RF(j,i-1,0)
			{
				temp[j]=m[j];
				if(temp[j]>temp[j+1])
				{
					sum+=temp[j]-temp[j+1];
					temp[j]=temp[j+1];
				}
			}
			sum+=m[i]-temp[i];
			if(minsum>sum || (i==0 && temp[i]==m[i]))
			{
				minsum=sum;
				maxindex=i;
				maxval=temp[i];
			}

			// F(q,0,n-1){cout<<" - "<<temp[q];}cout<<" ---- "<<maxindex<<" - "<<maxval<<" ( "<<sum<<" ) ";nl;
		// }
		// nl;
	}

	m[maxindex]=maxval;
	F(j,maxindex+1,n-1)
	{
		if(m[j]>m[j-1])
		{
			m[j]=m[j-1];
		}
	}
	RF(j,maxindex-1,0)
	{
		if(m[j]>m[j+1])
		{
			m[j]=m[j+1];
		}
	}

	F(i,0,n-1)cout<<m[i]<<" ";

	return 0;
}