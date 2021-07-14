//https://codeforces.com/contest/1341/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 23-04-2020 21:17:18
*/

#include<bits/stdc++.h>
using namespace std;

int MOD = 1e9 + 7; /*more than (10)^9*/
int PEG = 998244353; /*less than (10)^9*/	/*1 + 7*17*(2)^23*/
const double pie=acos(-1);

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

    int p[n+1],inp[n+1];p[0]=0;inp[0]=0;

    // int r[n+2];
    // r[0]=-1;
    // r[n+1]=-1;
    // int count[n+2]={};
   
    

    F(i,1,n)
    {
        cin>>p[i];
        inp[p[i]]=i;
    }

    int nav[n+2]={};
    nav[inp[1]]=1;
    
    nav[n+1]=1;

    if(n==1){pfy;return;}


    F(i,2,n)
    {
        
        if(inp[i]==inp[i-1]+1)
        {
            nav[inp[i]]=1;
            continue;
        }

        if(nav[inp[i-1]+1])
        {
            nav[inp[i]]=1;
            continue;
        }

        pfn;return;

    }

    pfy;
}
  
signed main()
{
    #ifndef ONLINE_JUDGE
    //freopen("input.txt","r",stdin);
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