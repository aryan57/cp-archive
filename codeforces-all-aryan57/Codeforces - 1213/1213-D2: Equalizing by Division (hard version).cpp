//https://codeforces.com/contest/1213/problem/D2

/*
    author : Aryan Agarwal, IIT KGP
    created : 23-December-2020 19:12:58 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 2e5;
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

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve_LOG()
{
    int n,k;
    cin>>n>>k;

    vector <int> a(n);
    vector <int> cnt(mxn+1);
    vector <int> vec;
    F(i,0,n-1)
    {
        cin>>a[i];
        cnt[a[i]]++;

        int x=a[i];
        int op=0;
        while(x)
        {
            x/=2;
            op++;
        }
        vec.pb(op);

    }


    sort(all(vec));
    int ans=0;
    F(i,0,k-1)
    {
        ans+=vec[i];
    }

    // dbg(ans);

    vector <int> pre(mxn+1);

    F(i,1,mxn)
    {
        pre[i]=pre[i-1]+cnt[i];
    }

    F(i,1,2e5)
    {
        int l,r;
        int z=1;
        int height=0;
        int op=0;
        int req=k;
        while(true)
        {
            l=z*i;
            r=min(mxn,z*i+z-1);
            if(l>mxn)break;
            // dbg(l,r);
            if(pre[r]-pre[l-1]<req)
            {
                req-=pre[r]-pre[l-1];
                op+=(pre[r]-pre[l-1])*(height);
            }
            else
            {
                op+=(req)*(height);
                req=0;               
                break;
            }
            z*=2;
            height++;
        }

        // dbg(op,req);
        
        if(req==0)ans=min(ans,op);
    }

    cout<<ans;
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
        solve_LOG();
    }
    return 0;
}