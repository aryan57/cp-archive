//https://codeforces.com/contest/1334/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 11-December-2020 01:30:38 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than (10)^9*/ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(a) cout<<"["<<#a<<" : "<<a<<"]\n"
#define dbg2(a,b) cout<<"["<<#a<<" : "<<a<<"], "<<"["<<#b<<" : "<<b<<"]\n"
#define dbg3(a,b,c) cout<<"["<<#a<<" : "<<a<<"], "<<"["<<#b<<" : "<<b<<"], "<<"["<<#c<<" : "<<c<<"]\n"

void solve()
{
    int n,l,r;
    cin>>n>>l>>r;

    if(l==r && l==n*n-n+1)
    {
        cout<<1;
        cout<<"\n";
        return;
    }

    int len=r-l+1;
    vector <int> ans;

    int b=1;
    while((b*(2*n-b-1))<l)b++;
    int z=b*(2*n-b-1)-2*(n-b);
    
    F(i,b+1,n)
    {
        int ind=2*(i-b)-1;
        if(ind+z==l)
        {
            F(j,i,n)
            {
                if(len)ans.pb(b),len--;
                if(len)ans.pb(j),len--;
            }
            break;

        }
        ind++;
        if(ind+z==l)
        {
            if(len)ans.pb(i),len--;;
            F(j,i+1,n)
            {
                if(len)ans.pb(b),len--;
                if(len)ans.pb(j),len--;
            }
            break;
        }

    }

    F(i,b+1,n-1)
    {
        if(!len)break;
        
        F(j,i+1,n)
        {
            if(!len)break;
            
            if(len)ans.pb(i),len--;
            if(len)ans.pb(j),len--;

            
        }
    }

    if(len)ans.pb(1),len--;

    for(int x :ans)cout<<x<<" ";
    cout<<"\n";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
    fact_init();
#endif
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}