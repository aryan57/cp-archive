//https://codeforces.com/contest/1341/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 23-04-2020 20:29:15
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
#define out(a,n) F(i,1,n)cout<<a[i]<<" ";cout<<"\n"
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
    int n,k;
    cin>>n>>k;

    int a[n+1],p[n+1]={},pre[n+1]={};

    F(i,1,n)
    {
        cin>>a[i];
    }

    
    F(i,2,n-1)
    {
        if(a[i]>a[i-1] && a[i]>a[i+1])p[i]=1;
        else p[i]=0;

        pre[i]=pre[i-1];
        pre[i]+=p[i];
    }

    pre[n]=pre[n-1];

    // cout<<"**";nl;
    // out(p,n);
    // out(pre,n);

    // cout<<"**";nl;

    int max=0;
    int temp=0;

    int ans=1;

    F(l,1,n-k+1)
    {
        temp=pre[l+k-1-1]-pre[l]+1;
        // if(p[l+k-1]==1)temp--;
        // if(p[l]==1)temp--;
        if(max<temp)
        {
            max=temp;
            ans=l;
        }
    }

    cout<<max<<" "<<ans;
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