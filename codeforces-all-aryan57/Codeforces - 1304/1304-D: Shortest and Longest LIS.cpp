//https://codeforces.com/contest/1304/problem/D

/*
    author : Aryan Agarwal, IIT KGP
    created : 14-December-2020 15:40:43 IST
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

// Returns 'length' of Longest Increasing Subsequence (LIS)
// d[i] is the element at which a subsequence of length 'i' terminates.
// If there are multiple such sequences, then we take the one that ends in the smallest element
// O(nlogn) - Binary Search
// Property 'd' will be an non-decreasing array
int lis_length(vector<int> const& a) {
    int n = a.size();
    const int INF = 1e9;
    vector<int> d(n+1, INF);
    d[0] = -INF;

    for (int i = 0; i < n; i++) {
        int j = upper_bound(d.begin(), d.end(), a[i]) - d.begin();
        if (d[j-1] < a[i] && a[i] < d[j])
            d[j] = a[i];
    }

    int ans = 0;
    for (int i = 0; i <= n; i++) {
        if (d[i] < INF)
            ans = i;
    }
    return ans;
}

int n;
string s;
void fun()
{
    int p=1,q=n;
    
    F(i,0,n-2)
    {
        if(s[i]=='<')
        {
            cout<<p++<<" ";
        }
        else
        {
            cout<<q--<<" ";
        }

    }

    cout<<p;
    
}
void fun1()
{
    int p=1,q=n;
    // dbg(p,q);
    vector <int> v(n,-1);
    int str=-1;
    F(i,0,n-1)
    {
        if(s[i]=='<' && str==-1)
        {
            str=i;
            continue;
        }
        if(s[i]!='<' && str!=-1)
        {
            // dbg(i,n,str,q);
            RF(j,i,str)
            {
                // dbg(j,q);
                v[j]=q--;
            }
            str=-1;
            continue;
        }
        if(s[i]=='>')
        {
            v[i]=q--;
        }
    }
    F(i,0,n-1)
    {
        if(v[i]==-1)v[i]=q--;
    }

    F(i,0,n-1)cout<<v[i]<<" ";
    // dbg(lis_length(v));
    
}

void solve()
{
    cin>>n;
    cin>>s;
    s+='$';
    fun1();
    cout<<"\n";
    // reverse(all(s));
    fun();
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