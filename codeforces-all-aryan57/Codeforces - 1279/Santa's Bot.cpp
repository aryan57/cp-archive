/*
    author : Aryan Agarwal, IIT KGP
    created : 19-December-2020 12:15:06 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
// const int32_t M = 1000000007; /*more than (10)^9*/ /*7 + 1e9*/
const int32_t M = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

int binpow(int x, int y=M-2, int p=M) /* (x^y)%p in O(log y) */
{
    int res = 1;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    return res;
}

void solve()
{
    int n;
    cin>>n;

    vector <int> k(n);
    vector <int> a[n];
    map<int,int> mp;

    F(i,0,n-1)
    {
        cin>>k[i];
        a[i].resize(k[i]);
        F(j,0,k[i]-1)
        {
            cin>>a[i][j];
            mp[a[i][j]]++;
        }
    }

    int ans=0;

    F(i,0,n-1)
    {

        int b=k[i]*n*n;

        int s=0;

        F(j,0,k[i]-1)
        {
            s+=mp[a[i][j]];
        }

        // dbg(s,b);

        for(int i=2;i*i<=s;i++)
        {
            while(s%i==0 && b%i==0)
            {
                s/=i;
                b/=i;
            }
        }

        if(b%s==0)
        {
            b/=s;
            s=1;
        }

        // dbg(s,b);

        s%=M;
        b%=M;

        int z=1;
        z*=s;
        z%=M;
        z*=binpow(b);
        z%=M;


        ans+=z;
        ans%=M;
    }

    cout<<ans;

    // int z=7;
    // z*=binpow(8);
    // z%=M;
    // dbg(z);

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
    // cout<<fixed<<setprecision(10);
    int _t=1;
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}