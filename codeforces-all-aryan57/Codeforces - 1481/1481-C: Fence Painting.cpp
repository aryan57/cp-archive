//https://codeforces.com/contest/1481/problem/C

/*
    author : Aryan Agarwal, IIT KGP
    created : 05-February-2021 20:51:05 IST
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

    int a[n+1],b[n+1],c[m+1];

    // int cntb[n+1]={};
    int indb[n+1]={};

    F(i,1,n)
    {
        cin>>a[i];
    }
    F(i,1,n)
    {
        cin>>b[i];
        indb[b[i]]=i;
    }
    F(i,1,m)
    {
        cin>>c[i];
    }

    vector<set<int>> col(n+1);

    set<int> ind;

    F(i,1,n)
    {
        if(b[i]!=a[i])
        {
            col[b[i]].insert(i);
            ind.insert(i);
        }
    }

    int ans[m+1];

    F(i,1,m)
    {
        if(!col[c[i]].empty())
        {
            int x=*col[c[i]].begin();

            ans[i]=x;
            a[x]=c[i];
            col[c[i]].erase(x);
            ind.erase(x);
            continue;
        }
        if(!ind.empty())
        {
            int x=*ind.begin();

            ans[i]=x;
            a[x]=c[i];
            // col[c[i]].erase(x);
            // ind.erase(x);
            continue;
        }

        if(indb[c[m]])
        {
            F(j,i,m)
            {
                ans[j]=indb[c[m]];
                a[indb[c[m]]]=c[m];
            }
            break;
        }
        else{
            cout<<"NO\n";
            return;
        }
    }

    F(i,1,n)
    {
        if(a[i]!=b[i])
        {
            cout<<"NO\n";
            return;
        }
    }

    cout<<"YES\n";
    F(i,1,m)cout<<ans[i]<<" ";
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