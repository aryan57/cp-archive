//https://codeforces.com/contest/1315/problem/B

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

	int t,a,b,p,n,ind,tot,flag;
	char s[(int)1e5+1];
	cin>>t;
	while(t--){
		cin>>a>>b>>p;
		// cout<<a<<b<<p;nl;
		cin>>s;
		n=strlen(s);

		// cout<<n;

		tot=0;flag=1;
		

		F(i,0,n-2){
			if(s[i]!=s[i+1])
			{
				if(s[i]=='A')tot+=a;
				else tot+=b;
			}

		}
		if(s[n-1]==s[n-2])
		{
			if(s[n-1]=='A')tot+=a;
			else tot+=b;
		}

		// cout<<"**"<<tot<<"**";

		F(i,0,n-3){
			if(p-tot<0){
				if(s[i]!=s[i+1]){
				if(s[i]=='A')tot-=a;
				else tot-=b;
				}
			}
			else {ind=i;flag=0;break;}
		}

		
		if(flag){if(p-tot<0){ind=n-1;}
		else ind=n-2;}

		cout<<ind+1<<"\n";


	}

	return 0;
}		