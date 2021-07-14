//https://codeforces.com/contest/1326/problem/D1

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

#define debug(x,y) cout<<(#x)<<" " <<(#y)<<" is " << (x) <<" "<< (y) <<"\n"
#define watch(x) cout<<(#x)<<" is " << (x) <<"\n"
#define int ll
#define F(i,a,b) for (ll i=a;i<=b;i++)
#define RF(i,a,b) for(ll i=a;i>=b;i--)
#define in(a,n) F(i,0,n-1)cin>>a[i]
#define in1(a,n) F(i,1,n)cin>>a[i]
#define out(a,n) F(i,0,n-1)cout<<"a[i] ";cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"
#define gcd(a,b) __gcd((a),(b))

bool isprime(int a){if(a==1){return false;}for(int i=2;i*i<=a;i++){if(a%i==0){return false;}}return true;}
bool iscoprime(int a,int b){int i;for(i=2;i<=min(a,b);i++){if(a%i==0 && b%i==0){ return false;}}return true;}
int binpow(int x,int y,int p)/* (x^y)%p in O(log y) */{int res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
int mod_inverse(int n,int p)/* Returns n^(-1) mod p */{return binpow(n,p-2,p);}
int NCR(int n, int r)/* find nCr */{/*p holds the value of n*(n-1)*(n-2)...*//*k holds the value of r*(r-1)...*/int p=1,k=1;/*C(n, r) == C(n, n-r) thus choosing the smaller value*/if (r>n-r)r=n-r;if (r != 0) {while(r){p *= n;k *= r;/*gcd of p, k*/int m = __gcd(p, k);/*dividing by gcd, to simplify product*//*division by their gcd saves from the overflow*/ p /= m; k /= m; n--;r--;}/* k should be simplified to 1 as C(n, r) is a natural number (denominator should be 1 )*/} else p = 1;/* if our approach is correct p = ans and k =1 */return p;}
int NCRmod(int n, int r, int p)/* nCr % p using Fermat's little theorem */{/*Base case*/if(r==0)return 1;/*Fill factorial array so that we can find all factorial of r, n and n-r*/int fac[n+1];fac[0] = 1;for(int i=1 ; i<=n; i++)fac[i]=fac[i-1]*i%p;return (fac[n]*mod_inverse(fac[r],p)%p*mod_inverse(fac[n-r],p)%p)%p;}
// int addmod(int a,int b,int p){return ( (a)%p + (b)%p )%p;}
// int submod(int a,int b,int p){return ( (a)%p - (b)%p )%p;}
// int mulmod(int a,int b,int p){return ( (a)%p * (b)%p )%p;}

int longestPrefixSuffix(string s) 
{ 
    int n = s.length(); 
  
    int lps[n]; 
    lps[0] = 0; // lps[0] is always 0 
  
    // length of the previous 
    // longest prefix suffix 
    int len = 0; 
  
    // the loop calculates lps[i] 
    // for i = 1 to n-1 
    int i = 1; 
    while (i < n) 
    { 
        if (s[i] == s[len]) 
        { 
            len++; 
            lps[i] = len; 
            i++; 
        } 
        else // (pat[i] != pat[len]) 
        { 
            // This is tricky. Consider 
            // the example. AAACAAAA 
            // and i = 7. The idea is 
            // similar to search step. 
            if (len != 0) 
            { 
                len = lps[len-1]; 
  
                // Also, note that we do 
                // not increment i here 
            } 
            else // if (len == 0) 
            { 
                lps[i] = 0; 
                i++; 
            } 
        } 
    } 
  
    int res = lps[n-1]; 
  
    // Since we are looking for 
    // non overlapping parts. 
    int ans= (res > n/2)? n/2 : res; 
    return ans-1;
}
 
 
void solve()
{
    string s,w;
    cin>>s;
    
    int k=-1,n=s.size();
 
    for(int i=0;i<n/2;i++)if(s[i]!=s[n-1-i]){k=i-1;break;}
    
 
    string a=s.substr(k+1,n-2-2*k);
    string ra=a;
    reverse(ra.begin(),ra.end());
 
    int p1=longestPrefixSuffix(a+'#'+ ra);
    int p2=longestPrefixSuffix(ra+'#'+ a);
 
    w = p1>=p2?a.substr(0,p1+1):ra.substr(0,p2+1);
    // cout<<w<<"+"<<k;nl;
 
 
 
    string ans=s.substr(0,k+1)+w+s.substr(n-1-k,k+1);
    // cout<<s.substr(0,k+1)<<"+"<<w<<"+"<<s.substr(n-1-k,k+1)<<"\n";
    cout<<ans<<"\n";
 
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