//https://codeforces.com/contest/1312/problem/B

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

bool comp(int a,int b){
    return a>b;
}
void solve()
{
    int n;
    cin>>n;
    int a[n],temp;
    F(i,0,n-1)
    {
        cin>>a[i];

    }

    sort(a,a+n,comp);
    F(i,0,n-1)cout<<a[i]<<" ";nl;
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