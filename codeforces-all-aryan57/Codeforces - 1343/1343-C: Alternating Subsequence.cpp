//https://codeforces.com/contest/1343/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 21-04-2020 20:25:55
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

    int a[n+1];

    a[0]=0;
    in1(a,n);

    int ps=0,ns=0;
    int temp=1;
    
    int la1=0;

    int cp=0,cn=0;
    

    F(i,1,n)
    {
        // watch(ps);
        // watch(ns);
        if(a[i]>0 && temp==-1){ps-=la1;ps+=max(la1,a[i]);la1=max(la1,a[i]);continue;}
        if(a[i]<0 && temp==1){ps-=la1;ps+=max(la1,a[i]);la1=max(la1,a[i]);continue;}

        if(temp==1 && a[i]>0)
        {
            ps+=a[i];temp=-1;la1=a[i];cp++;
        }
        if(temp==-1  && a[i]<0){ps+=a[i];temp=1;la1=a[i];cp++;}


        
    }
    // watch(ps);
    //     watch(ns);

    int temp2=-1;
    int la2=0;
    F(i,1,n)
    {
        // watch(ps);
        // watch(ns);

        if(a[i]>0 && temp2==-1 && abs(la2)){ns-=la2;ns+=max(la2,a[i]);la2=max(la2,a[i]);continue;}
        if(a[i]<0 && temp2==1 && abs(la2)){ns-=la2;ns+=max(la2,a[i]);la2=max(la2,a[i]);continue;}

     

        if(temp2==-1  && a[i]<0){ns+=a[i];temp2=1;la2=a[i];cn++;}
        if(temp2==1 && a[i]>0){ns+=a[i];temp2=-1;la2=a[i];cn++;}

        
    }

    // watch(ps);
    //     watch(ns);

    if(cp==cn)cout<<max(ps,ns);
    if(cp>cn)cout<<ps;
    if(cp<cn)cout<<ns;
    
    nl;
}
 
signed main()
{
    //freopen("input.txt","r",stdin);
    fast;
 
    int _t;
    cin>>_t;
    while(_t--)
    {
        solve();
    }
 
    return 0;
}