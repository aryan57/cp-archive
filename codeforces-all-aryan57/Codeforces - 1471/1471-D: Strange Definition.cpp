//https://codeforces.com/contest/1471/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 05-January-2021 21:35:20 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e6;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than 1e9 */ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than 1e9 */   /*1 + 7*17*(1<<23) */
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

#define ARYAN_SIEVE  
const int mxn_sieve = 1e6;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
void sieve()
{
    spf[1] = 1;
    for (int i = 2; i <= mxn_sieve; i++)
        spf[i] = i;

    for (int i = 4; i <= mxn_sieve; i += 2)
        spf[i] = 2;

    for (int i = 3; i * i <= mxn_sieve; i++)
    {
        if (spf[i] == i)
        {
            for (int j = i * i; j <= mxn_sieve; j += i)
                if (spf[j] == j)
                    spf[j] = i;
        }
    }
}

void solve_LOL()
{
    int n;
    cin>>n;

    int a[n];
    map<int,int> cnt;
    int ans=-INF;
    F(j,0,n-1)
    {
        cin>>a[j];
        int res=1;
        while(a[j]>1)
        {
            int cnt=0;
            int z=spf[a[j]];
            while(a[j]%z==0)
            {
                cnt++;
                a[j]/=z;
            }

            if(cnt%2)res*=z;
        }

        a[j]=res;
        cnt[a[j]]++;
        ans=max(ans,cnt[a[j]]);
    }


    for(pair <int,int> p:cnt)
    {
        int k=p.Y;
        if(k%2==0)
        {
            cnt[1]+=k;
            cnt[p.X]-=k;
        }
    }


    int ans2=-INF;

    for(pair <int,int> p:cnt)
    {
        ans2=max(ans2,p.Y);
    }

    int q;
    cin>>q;

    int w;

    while(q--)
    {
        cin>>w;
        if(w==0)
        {
            cout<<ans;
        }
        else
        {
            cout<<ans2;
        }
        
        cout<<"\n";
    }



}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    cout.tie(nullptr);
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}