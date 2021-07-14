//https://codeforces.com/contest/1519/problem/D

/*
    author : aryan57
    created : 29-April-2021 21:17:40 IST
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

int fun2(vector <int> a,vector <int> b,int s,int n)
{
    int mx=s;

    F(i,0,n-1)
    {
        int delta=0;
        F(j,1,n)
        {
            if(i-j<0 || i+j>n-1)break;
            delta+=(a[i+j]-a[i-j])*(b[i-j]-b[i+j]);
            mx=max(mx,s+delta);
        }
    }

    return mx;
}
int fun3(vector <int> a,vector <int> b,int s,int n)
{
    int mx=s;

    F(i,0,n-2)
    {
        int delta=0;
        F(j,0,n)
        {
            if(i-j<0 || i+1+j>n-1)break;
            delta+=(a[i+1+j]-a[i-j])*(b[i-j]-b[i+1+j]);
            mx=max(mx,s+delta);
        }
    }

    return mx;
}

void solve_LOG()
{
    int n;
    cin>>n;

    vector <int> a(n);
    vector <int> b(n);

    F(i,0,n-1)
    {
        cin>>a[i];
    }

    int s1=0;
    F(i,0,n-1)
    {
        cin>>b[i];
        s1+=a[i]*b[i];
    }


    int s2=fun2(a,b,s1,n);
    int s3=fun3(a,b,s1,n);

    dbg(s1,s2,s3);

    cout<<max({s1,s2,s3});
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