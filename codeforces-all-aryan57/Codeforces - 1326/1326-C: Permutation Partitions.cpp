//https://codeforces.com/contest/1326/problem/C

/*
    author : aryan57
*/
#include<bits/stdc++.h>
using namespace std;
int MOD = 1e9 + 7;
int M = 998244353;
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

struct arr{
    int v;
    int ind;

};

bool comp(arr a,arr b){
    return (a.v>b.v);
}

bool comp2(arr a,arr b){
    return (a.ind>b.ind);
}

signed main()
{
    fast;

    int n,k,sum=0,mm=1;
    cin>>n>>k;
    arr p[n];

    F(i,0,n-1){cin>>p[i].v;p[i].ind=i+1;}

    sort(p,p+n,comp);

    F(i,0,k-1)sum+=p[i].v;

    sort(p,p+k,comp2);

    F(i,1,k-1){
        // cout<<p[i].ind-p[i-1].ind<<"=";
        mm=((mm%M)*((p[i].ind-p[i-1].ind)%M))%M;}
    

    cout<<sum<<" "<<abs(mm);


    return 0;
}