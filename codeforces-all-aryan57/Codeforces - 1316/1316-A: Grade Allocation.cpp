//https://codeforces.com/contest/1316/problem/A

/*
    author: aryan57
*/
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
#define fast ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
#define pfy cout<<"YES"
#define pfn cout<<"NO"
#define pfn1 cout<<"-1"  // printf negative 1
#define pf1 cout<<"1"
#define nl cout<<"\n"
 
 
signed main()
{
    #ifndef ONLINE_JUDGE 
    freopen("input.txt", "r", stdin); 
    #endif
    fast;

    int t;
        int n,m,sum;
    cin>>t;
    while(t--)
    {
        sum=0;
        cin>>n>>m;
        int a[n+1];
        F(i,1,n)
        {
            cin>>a[i];
            sum+=a[i];
        }

        if(sum>m)cout<<m;
        else cout<<sum;

        nl;

    }

    return 0;
}