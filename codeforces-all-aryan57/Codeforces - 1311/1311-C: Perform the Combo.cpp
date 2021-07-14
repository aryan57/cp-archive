//https://codeforces.com/contest/1311/problem/C

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

	int t,n,m,*count,ans[27]={};

	cin>>t;
	while(t--)
	{
		int ans[27]={};
		
		cin>>n>>m;

		count=(int*)calloc(n+1,sizeof(int));

		char s[n+2];
		int p[m+1];

		F(i,1,n)
		{
			cin>>s[i];
			ans[s[i]-'a'+1]++;
		}

		F(i,1,m)
		{
			cin>>p[i];
			count[p[i]]++;
		}

		RF(i,n-1,1)
		{
			count[i]+=count[i+1];
			ans[s[i]-'a'+1]+=count[i];
			// cout<<"-- "<<count[i]<<" --";
		}


		F(i,1,26){cout<<ans[i]<<" ";}nl;

		free(count);

	}

	return 0;
}