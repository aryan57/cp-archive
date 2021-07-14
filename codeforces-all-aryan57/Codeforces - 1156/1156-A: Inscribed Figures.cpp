//https://codeforces.com/contest/1156/problem/A

/*
    author : aryan57
    created : 28-April-2021 07:41:52 IST
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
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_LOG()
{
    int n;
    cin>>n;

    int a[n];
    bool ok = true;
    int cnt=0;
    F(i,0,n-1)
    {
        cin>>a[i];
        if(i && a[i]==2 && a[i-1]==3)ok=false;
        if(i && a[i]==3 && a[i-1]==2)ok=false;
        if(i && a[i]==a[i-1])ok=false;

        if(i && a[i]==1 && a[i-1]==3)cnt+=4;
        if(i && a[i]==3 && a[i-1]==1)cnt+=4;
        if(i && a[i]==1 && a[i-1]==2)cnt+=3;
        if(i && a[i]==2 && a[i-1]==1)cnt+=3;
    }

    F(i,2,n-1)
    {
        if(a[i-2]==3 && a[i-1]==1 && a[i]==2)cnt--;
    }

    if(ok)cout<<"Finite\n"<<cnt;
    else cout<<"Infinite";
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