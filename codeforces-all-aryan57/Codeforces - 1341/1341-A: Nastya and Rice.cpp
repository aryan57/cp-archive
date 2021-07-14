//https://codeforces.com/contest/1341/problem/A

/*
    author : Aryan Agarwal, IIT KGP
    created : 24-04-2020 22:46:20
*/

#include<bits/stdc++.h>
using namespace std;

typedef long long int ll;
typedef unsigned long long ull;
#define int ll

int MOD = 1000000007; /*more than (10)^9*/  /*7 + 1e9*/
int M = 998244353; /*less than (10)^9*/	/*1 + 7*17*(2)^23*/
double pie=acos(-1);

typedef vector<int> vi;
#define X first
#define Y second
#define pb push_back
#define sz(a) (ull)(a).size()
#define all(a) (a).begin(),(a).end()
 
#define db(x) cout<<#x<<" = "<<x<<"\n"
#define db2(x, y) cout<<"("<<#x<<", "<<#y<<") = ("<<x<<", "<<y<<")\n"
#define db3(x, y, z) cout<<"("<<#x<<", "<<#y<<", "<<#z<<") = ("<<x<<", "<<y<<", "<<z<<")\n"
#define dbv(a) cout<<#a<<" = ";for(auto xxxx: a)cout<<xxxx<<" ";cout<< "\n"
 
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

ll binpow(ll x,ll y,ll p)/* (x^y)%p in O(log y) */{ll res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
ll mod_inverse(ll n,ll p)/* Returns n^(-1) mod p */{return binpow(n,p-2,p);}
ll popcount(ll n)/*builtin popcount doesn't work for big no.s*/{ll ans=0;while(n){if(n%2)ans++;n/=2;}return ans;}
ll gcd(ll a, ll b)/*builtin gcd doesn't work for big no.s*/{if (b == 0)return a;return gcd(b, a % b);}


void solve()
{
    int a,b,c,d,n;
    cin>>n>>a>>b>>c>>d;
 
    if(n*(a-b)>c+d || n*(a+b)<c-d)pfn;
 
 
    else pfy;
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