//https://codeforces.com/contest/1328/problem/D

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
#define out(a,n) F(i,0,n-1)cout<<"a[i] ";cout<<"\n"
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"
#define gcd(a,b) __gcd((a),(b))

struct arr{
    int v;
    int g;
};

bool comp(arr a,arr b){
    return a.v<b.v;
}

int binpow(int x,int y,int p)/* (x^y)%p in O(log y) */{int res=1;x=x%p;while (y > 0){if(y&1)res=(res*x)%p;y = y>>1;x=(x*x)%p;}return res;}
int mod_inverse(int n,int p)/* Returns n^(-1) mod p */{return binpow(n,p-2,p);}
 
void solve()
{
    int n,k=0,m,pair=-1;
    cin>>n;
    int t[n],temp=0;

    cin>>t[0];
    F(i,1,n-1){
        cin>>t[i];
        if(t[i]!=t[i-1])temp++;
        else pair=i;

    }

    if(!temp)
    {
        cout<<"1\n";
        while(n--)cout<<"1 ";nl;
    }
    else
    {
        
        if(n%2==0)
        {
            n/=2;
            cout<<"2\n";
            while(n--)
            cout<<"1 2 ";nl;
        }

        else
        {
             if(t[0]==t[n-1])
            {
                n/=2;
                cout<<"2\n";
                while(n--)
                cout<<"1 2 ";cout<<"1\n";
            }

            else if(pair==-1)
            {
                n/=2;
                cout<<"3\n";
                while(n--)
                cout<<"1 2 ";cout<<"3\n";
            }

            else
            {
                cout<<"2\n";
                // watch(pair);
                if((pair-1)%2==0)
                {
                    F(i,1,(pair-1)/2)cout<<"1 2 ";
                    cout<<"1 1 ";
                    if(pair+1<n)
                    {
                        cout<<"2 ";
                        F(i,1,(n-2-pair)/2)cout<<"1 2 ";nl;
                    }
                }
                else
                {
                    F(i,1,(pair-2)/2)cout<<"1 2 ";
                    cout<<"1 ";
                    cout<<"2 2 ";
                    F(i,1,(n-1-pair)/2)cout<<"1 2 ";nl;
                    
                }
            }
        }
        
        
        
        
    }
    

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