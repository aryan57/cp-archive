//https://codeforces.com/contest/1463/problem/D

/*
    // sol used...
    credits: @yash_daga
    author : Aryan Agarwal, IIT KGP
    created : 18-December-2020 12:24:57 IST
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
  cout << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cout.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

void solve()
{
    int n;
    cin>>n;

    vector <int> b(n),a(n),cnt(2*n+1,0);


    F(i,0,n-1){cin>>b[i];cnt[b[i]]++;}
    int ind=0;
    F(i,1,2*n)
    {
        if(cnt[i]==0)a[ind++]=i;
    }

    set<int> s[2][2];

    F(i,0,n-1)
    {
        if(b[i]>a[i])
        {
            s[0][0].insert(b[i]);
            s[0][1].insert(a[i]);
        }
        else
        {
            s[1][0].insert(b[i]);
            s[1][1].insert(a[i]);
        }
    }

    int ans=0;

    for(int x : s[0][0])
    {
        // auto it=upper_bound(all(s[0][1]),x);
        auto it=s[0][1].upper_bound(x);
        if(it!=s[0][1].end())
        {
            ans++;
            s[0][1].erase(it);
        }
        else
        {
            break;
        }
        
    }

    for(int x : s[1][1])
    {
        // auto it=upper_bound(all(s[1][0]),x);
        auto it=s[1][0].upper_bound(x);
        if(it!=s[1][0].end())
        {
            ans++;
            s[1][0].erase(it);
        }
        else
        {
            break;
        }
        
    }

    cout<<ans+1;
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
    // cout<<fixed<<setprecision(10);
    int _t=1;
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve();
    }
    return 0;
}