/*
    author : Aryan Agarwal, IIT KGP
    created : 26-December-2020 19:45:27 IST
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

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

int f1(int a[],int b[],int n)
{
    int mx=0;

    int z=min(a[0],b[1]);
    a[0]-=z;
    b[1]-=z;
    mx+=z;

    z=min(a[1],b[2]);
    a[1]-=z;
    b[2]-=z;
    mx+=z;

    z=min(a[2],b[0]);
    a[2]-=z;
    b[0]-=z;
    mx+=z;

    return mx;
}


int f2(int a[],int b[],int n)
{
    int ans=INF;

    vector <int> x(3);
    F(i,0,2)x[i]=i;
    int z;

    int ora[3],orb[3];

    F(i,0,2)
    {
        ora[i]=a[i];
        orb[i]=b[i];
    }

    do
    {
        F(i,0,2)
        {
            a[i]=ora[i];
            b[i]=orb[i];
        }
        
        F(i,0,2)
        {
            z=min(a[x[i]],b[x[i]]);
            a[x[i]]-=z;
            b[x[i]]-=z;
            z=min(a[x[i]],b[(x[i]+2)%3]);
            a[x[i]]-=z;
            b[(x[i]+2)%3]-=z;
        }

        int cur=0;

        F(i,0,2)
        {
            z=min(a[i],b[(i+1)%3]);
            a[i]-=z;
            b[(i+1)%3]-=z;
            cur+=z;
        }

        ans=min(ans,cur);

    } while (next_permutation(all(x)));
    

    return ans;
}

void solve_LOG()
{
    int n;
    cin>>n;

    int a[3],b[3];
    int c[3],d[3];
    F(i,0,2){cin>>a[i];c[i]=a[i];}
    F(i,0,2){cin>>b[i];d[i]=b[i];}

    cout<<f2(a,b,n)<<" "<<f1(c,d,n);

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