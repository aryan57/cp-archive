//https://codeforces.com/contest/1333/problem/B

/*
    author : Aryan Agarwal, 19CS30005, IIT KGP
*/

#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7; /*more than (10)^9*/
int PEG = 998244353; /*less than (10)^9*/	/*1 + 7*17*(2)^23*/
const double pie=2*acos(0.0);

typedef long long int ll;
typedef unsigned long long ull;

#define watch(x) cout<<(#x)<<" is " << (x) <<"\n"
#define int ll
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<a[i]<<" ";cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"
#define gcd(a,b) __gcd((a),(b))

int binpow(int x,int y,int p)/* (x^y)%p in O(log y) */{int res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
int mod_inverse(int n,int p)/* Returns n^(-1) mod p */{return binpow(n,p-2,p);}
 
void solve()
{
    int n;
    cin>>n;
    int a[n],b[n];
    in(a,n);
    in(b,n);

    int inc=0,dec=0;
    if(a[0]!=b[0]){pfn;nl;return;}
    if(a[0]==1)inc=1;
    if(a[0]==-1)dec=1;

    F(i,1,n-1)
    {
        
            if(b[i]>a[i] && inc==0){pfn;nl;return;}
            if(b[i]<a[i] && dec==0){pfn;nl;return;}
            if(a[i]==1 && inc==0)inc=1;
            if(a[i]==-1 && dec==0)dec=1;
        
    }
    pfy;nl;

}
 
signed main()
{
    fast;
 
    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();
    }
 
    return 0;
}