//https://codeforces.com/contest/1348/problem/C

/*
	author : Aryan Agarwal, IIT KGP
	created : 01-05-2020 22:48:47
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define int ll

int MOD = 1000000007; /*more than (10)^9*/  /*7 + 1e9*/
int PEG = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
long double pie=acos(-1);

// while using ceil() function,always type cast the parameters to double like ceil((1.0*a)/b)

// for creating a 2d vector with n rows & m columns then initialise it with it 0
// vvi vec(n,vi(m,0));
// vector<vector<int> > vec( n , vector<int> (m, 0));
typedef vector< int > vi;
typedef vector< vi > vvi;
#define X first
#define Y second
#define pb push_back
#define sz(a) (ull)(a).size()
#define all(a) (a).begin(),(a).end()
 
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<"\n"
#define out1(a,n) F(i,1,n)cout<<a[i]<<" ";cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>void __f(const char* name,Arg1&& arg1){std::cout<<name<<" : "<<arg1<<endl;}template <typename Arg1,typename... Args>void __f(const char* names,Arg1&& arg1,Args&&... args){const char* comma=strchr(names+1, ',');std::cout.write(names,comma-names)<<" : "<<arg1<<"\n";__f(comma+1,args...);}

ll binpow(ll x,ll y,ll p)/* (x^y)%p in O(log y) */{ll res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpow(n,p-2,p);}
ll popcount(ll n)/*__builtin_popcount doesn't work for big no.s*/{ll ans=0;while(n){if(n%2)ans++;n/=2;}return ans;}
ll gcd(ll a, ll b)/*__gcd doesn't work for big no.s*/{if (b == 0)return a;return gcd(b, a % b);}

void solve()
{
	int n,k;
	cin>>n>>k;
	
	vector <string> v(k,"");
	string s;
	cin>>s;
	int alp[26]={};
	F(i,0,n-1)
	{
		alp[s[i]-'a']++;
	}


	if(sz(s)==1){cout<<s;return;}
	sort(all(s));

	int flag=0;
	F(i,0,k-1)
	{
		
		if(i)
		{
			if(s[i]!=s[i-1])flag=1;
		}
		v[i]=s[i];
		alp[s[i]-'a']--;

	}

	if(flag==1)
	{
		cout<<v[k-1];
		return;
	}

	int temp=0;
	char tempchar;

	int pp[27]={};
	RF(i,25,0)
	{
		pp[i]=pp[i+1];
		if(alp[i])pp[i]++;
	}

	F(i,0,25)
	{
		if(alp[i]!=0 && pp[i+1]==0)
		{
			temp=ceil((1.0*alp[i])/k);
			tempchar='a'+i;
			while(temp--)
			{
				v[0]+=tempchar;
			}
			break;
		}
		if(alp[i]!=0 && pp[i+1]!=0)
		{
			v[0]+=s.substr(k,n-k);
			break;
		}
	}

	cout<<v[0];

}
  
signed main()
{
	#ifndef ONLINE_JUDGE
	// freopen("input.txt","r",stdin);
	#endif
	fast;

	int _t;
	cin>>_t;
	while(_t--)
	{
		solve();
		cout<<"\n";
	}

	return 0;
}