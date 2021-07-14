//https://codeforces.com/contest/1335/problem/E1

/*
    author : Aryan Agarwal, IIT KGP
    created : 15-04-2020 11:37:59
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
    vector<vector<int> > pre( 27 , vector<int> (n+1, 0)); 
    int a[n+1]={};
    int max=0;

    F(i,1,n)
    {
        cin>>a[i];
        
        F(j,1,26)
        {
            pre[j][i]=pre[j][i-1];
        }
        
        pre[a[i]][i]++;
        if(max<pre[a[i]][i])max=pre[a[i]][i];
    }

    F(i,1,n)
    {
        F(j,i,n)
        {
            int cntout=0;
            int cntin=0;
            int temp=0;
            F(k,1,26)
            {
                temp=min(pre[k][i-1],pre[k][n]-pre[k][j]);
                if(cntout<temp)cntout=temp;

                temp=pre[k][j]-pre[k][i-1];
                if(cntin<temp)cntin=temp;
            }
            // watch(cntin);
            // watch(cntout);
            if(max< 2*cntout + cntin)max=2*cntout + cntin;
        }
    }

    cout<<max;nl;

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