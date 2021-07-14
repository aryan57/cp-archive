//https://codeforces.com/contest/1496/problem/B

/*
    author : Aryan Agarwal, IIT KGP
    created : 12-March-2021 16:12:08 IST
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

int ceil(int a, int b)
{
    return (a + b - 1) / b;
}

void solve_LOG()
{
    int n,k;
    cin>>n>>k;

    // multiset<int> s;
    set<int> s2;

    // F(i,0,2e5)
    // {
    //     s.insert(i);
    // }

    int a[n];
    int mx=-1;
    F(i,0,n-1)
    {
        cin>>a[i];
        s2.insert(a[i]);
        mx=max(mx,a[i]);
        // auto it=s.find(a[i]);
        // if(it!=s.end())
        // {
        //     s.erase(a[i]);
        // }
    }

    while (true)
    {
        if(k==0)break;

        int mex=INF;
        
        F(i,0,2*sz(s2)+1000)
        {
            if(s2.find(i)==s2.end())
            {
                mex=i;
                break;
            }
        }

        if(mex>mx)
        {
            cout<<sz(s2)+k;
            cout<<"\n";
            return;
        }


        int p=ceil(mx+mex,2);

        mx=max(mx,p);
        s2.insert(p);
        k--;

        if(p>mex)
        {
            cout<<sz(s2);
            cout<<"\n";
            return;
        }

    }
    cout<<sz(s2);
    cout<<"\n";

    // if(k==0)
    // {
    //     
    //     return;
    // }
    


    


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
        solve_LOG();
    }
    return 0;
}