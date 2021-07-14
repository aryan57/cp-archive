//https://codeforces.com/contest/1196/problem/D2

/*
    author : Aryan Agarwal, IIT KGP
    created : 04-January-2021 16:51:21 IST
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

void solve_LOL()
{
    int n,k;
    cin>>n>>k;

    string s;
    cin>>s;

    // int cnt[3][3]={};
    int pre[n][3][3]={};

    // F(i,0,n-1)
    // {
    //     F(c,0,2)
    //         F(pos,0,2)
    //             pre[i][c][pos]=0;
    // }

    F(i,0,n-1)
    {
        int id=0;
        if(s[i]=='G')id=1;
        if(s[i]=='B')id=2;

        // cnt[id][i%3]++;

        if(i>=1)
       { F(c,0,2)
        {
            F(pos,0,2)
            {
                pre[i][c][pos]=pre[i-1][c][pos];
            }
        }}

        
        pre[i][id][i%3]++;

    }

    // dbg(pre[1][1][1]);

    int ans=INF;

    F(i,0,n-k)
    {
        F(id,0,2)
        {
            int c1,c2,c3;
            c1=pre[i+k-1][id][i%3];
            c2=pre[i+k-1][(id+1)%3][(i+1)%3];
            c3=pre[i+k-1][(id+2)%3][(i+2)%3];

            // dbg(i,c1,c2,c3);
            if(i>=1)
            {
                c1-=pre[i-1][id][i%3];
                c2-=pre[i-1][(id+1)%3][(i+1)%3];
                c3-=pre[i-1][(id+2)%3][(i+2)%3];
            }
            // dbg(i,c1,c2,c3);

            int n1,n2,n3;
            n1=n2=n3=k/3;
            if(k%3>=1)n1++;
            if(k%3>=2)n2++;


            int z=0;
            z+=n1-c1;
            z+=n2-c2;
            z+=n3-c3;

            ans=min(ans,z);
            // dbg(i,c1,c2,c3);
            // dbg(ans);
        }
    }

    cout<<ans;
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