//https://codeforces.com/contest/869/problem/C

/*
    // tut used
    author : aryan57
    created : 27-April-2021 18:49:30 IST
*/
#include <bits/stdc++.h>
using namespace std;

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

#define int long long
#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

const int mxn = 1e5;
const long long INF = 2e18;
// const int32_t M = 1000000007;
const int32_t M = 998244353;
const long double pie = acos(-1);

#define ARYAN_FACT
const int mxn_fact = 5*1e3+1;

int fact[mxn_fact + 1];
int invfact[mxn_fact + 1];

void fact_init()
{
    int p = M;

    fact[0] = 1;
    for (int i = 1; i <= mxn_fact; i++)
        fact[i] = (i * fact[i - 1]) % p;

    // res will be binpow(fact[mxn_fact],p-2,p)
    // binpow algo starts....
    int res = 1;
    int x = fact[mxn_fact], y = p - 2;
    x = x % p;
    while (y > 0)
    {
        if (y & 1)
            res = (res * x) % p;
        y = y >> 1;
        x = (x * x) % p;
    }
    // binpow algo ends....

    invfact[mxn_fact] = res;
    for (int i = mxn_fact - 1; i >= 0; i--)
        invfact[i] = (invfact[i + 1] * (i + 1)) % p;
}

int ncr(int n,int r)
{
    if(n<r)return 0;
    int ans=1;
    ans*=fact[n];
    ans%=M;
    ans*=invfact[n-r];
    ans%=M;
    ans*=invfact[r];
    ans%=M;
    return ans;
}

int fun(int a,int b){

    int ans=0;

    F(k,0,min(a,b))
    {
        int t=1;
        t*=fact[k];
        t%=M;
        t*=ncr(a,k);
        t%=M;
        t*=ncr(b,k);
        t%=M;

        ans+=t;
        ans%=M;
    }
    return ans;
}

void solve_LOG()
{
    int a,b,c;
    cin>>a>>b>>c;

    int ans=1;
    ans*=fun(a,b);
    ans%=M;
    ans*=fun(a,c);
    ans%=M;
    ans*=fun(b,c);
    ans%=M;

    cout<<ans;

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
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
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