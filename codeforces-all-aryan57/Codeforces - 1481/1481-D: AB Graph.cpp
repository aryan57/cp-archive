//https://codeforces.com/contest/1481/problem/D

/*
    credits: @CoderAnshu
    tut used...
    author : Aryan Agarwal, IIT KGP
    created : 05-February-2021 22:37:26 IST
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

    int a[n+1][n+1]={};

    char c;

    F(i,1,n)
    {
        F(j,1,n)
        {
            cin>>c;
            if(c=='a')a[i][j]=1;
            if(c=='b')a[i][j]=2;
        }
    }

    F(i,1,n)
    {
        F(j,1,n)
        {
            if(a[i][j]==a[j][i] && i!=j)
            {
                int cur=i;
                vector <int> ans;

                while(sz(ans)<m+1)
                {
                    ans.pb(cur);
                    cur^=(i^j);
                }

                cout<<"YES\n";
                for(int x : ans)cout<<x<<" ";
                cout<<"\n";
                return;
            }
        }
    }

    if(m%2==1)
    {
        int cur=1;
        vector <int> ans;

        while(sz(ans)<m+1)
        {
            ans.pb(cur);
            cur^=(1^2);
        }

        cout<<"YES\n";
        for(int x : ans)cout<<x<<" ";
        cout<<"\n";
        return;
    }

    if(n==2)
    {
        cout<<"NO\n";
        return;
    }

    vector <int> x={1,2,3};

    do
    {
        if(a[x[0]][x[1]]==a[x[1]][x[2]])
        {
            int p=x[0];
            int q=x[1];
            int r=x[2];

            bool zz= false;
            if(m%4==0)zz=true,m+=2;

            vector <int> ans;

            while (sz(ans)+4<=m-2)
            {
                ans.pb(p);
                ans.pb(q);
                ans.pb(r);
                ans.pb(q);
            }
            ans.pb(p);
            ans.pb(q);
            ans.pb(r);

            int l=0,rr=m;
            if(zz)l++,rr--;
            cout<<"YES\n";
            F(i,l,rr)cout<<ans[i]<<" ";
            cout<<"\n";
            return;
            
        }
    } while (next_permutation(all(x)));
    
    cout<<"NO\n";
    
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