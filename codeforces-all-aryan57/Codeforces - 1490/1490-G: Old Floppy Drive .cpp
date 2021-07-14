//https://codeforces.com/contest/1490/problem/G

/*
    author : Aryan Agarwal, IIT KGP
    created : 16-February-2021 21:14:03 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
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


void solve_LOL()
{
    int n,m;
    cin>>n>>m;

    int a[n];

    vector <int > v1;
    vector <int > v2;
    vector <int> pre(n);
    int p=1;
    int mx=-INF;
    F(i,0,n-1)
    {
        cin>>a[i];
        if(!i)pre[i]=a[i];
        else pre[i]=pre[i-1]+a[i];

        if(pre[i]>=p)
        {
            v1.pb(pre[i]);
            v2.pb(i);
            mx=max(mx,pre[i]);
            p=pre[i]+1;
        }

    }

    int tot=pre[n-1];

    int x;
    while(m--)
    {
        cin>>x;
        if(mx==-INF)
        {
            cout<<"-1 ";
            continue;
        }
        if(x<=mx)
        {
            int pos= lower_bound(v1.begin(),v1.end(),x)-v1.begin();
            // pos--;
            if(pos==sz(v1))
            {
                cout<<"-1 ";
                continue;
            }

            cout<<v2[pos]<<" ";
        }
        else
        {
            if(tot<=0)
            {
                cout<<"-1 ";
                continue;
            }

            int ans=-1;

            int l=1,r=1e9;

            while(l<=r)
            {
                int m=(l+r)/2;
                
                if((m-1)*tot + mx>=x)
                {
                    r=m-1;
                    continue;
                }
                if(m*tot + mx<x)
                {
                    l=m+1;
                    continue;
                }
                // dbg(l,r,m,x);
                int k=x-m*tot;
                if(k<0)
                {
                    r=m-1;
                    continue;
                }
                // if(k>mx)
                // {
                //     r=m-1;
                //     continue;
                // }


                int pos= lower_bound(v1.begin(),v1.end(),k)-v1.begin();
                // pos--;
                if(pos==sz(v1))
                {
                    ans=-1;
                }
                else{
                    ans=v2[pos]+m*n;
                }
                break;

                


            }

            cout<<ans<<" ";
        }

    }
    cout<<"\n";
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