//https://codeforces.com/contest/1312/problem/C

/*
    author : aryan57
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
 
void solve()
{
    int n,k;
    cin>>n>>k;
    int a[n];
    in(a,n);

    sort(a,a+n);

    int t=k,flag=1,count=0;
    F(i,0,n-1)
    {
        if(a[i]%t>1)
        {
            pfn;nl;flag=0;break;
        }
        else{
            if(a[i]%t)count++;
        }
        if(count>1)
        {
            pfn;nl;flag=0;break;
        }


        a[i]/=t;
        if(i==n-1){
            i=-1;count=0;
        }
        if(a[n-1]==0)break;
    }

    if(flag){
        pfy;nl;
    }
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