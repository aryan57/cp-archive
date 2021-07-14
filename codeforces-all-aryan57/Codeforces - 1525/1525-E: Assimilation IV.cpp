//https://codeforces.com/contest/1525/problem/E

/*
    author : aryan57
    created : 17-May-2021 11:22:26 IST
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
const int mxn_fact=20;
int fact[mxn_fact+1];

void fact_init()
{
    int MOD=M;
    fact[0]=1;
    for (int i=1;i<=mxn_fact;i++)
        fact[i]=(i*fact[i-1])%MOD;
}

/*
    modInverse(a) = binpow(a, phi(n)-1, n)
    If n is prime, phi(n) = n-1
    phi(n) = number of no.s from 1 to n co-prime with n
*/
int binpow(int a, int b=M-2, int m=M)
{
    assert(a>=0 && b>=0);
    a%=m;
    int res=1;
    while (b)
    {
        if(b%2)res=res*a%m;
        a=a*a%m;
        b/=2;
    }
    return res;
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;

    int d[n][m];
    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            cin>>d[i][j];
        }
    }

    int cnt=0;

    F(j,0,m-1)
    {
        vector <int> d1(n);
        F(i,0,n-1)
        {
            d1[i]=n+1-d[i][j];
        }

        sort(all(d1),greater<int> ());

        int cntj=fact[n];
        int t=1;
        F(i,0,n-1)
        {
            if(n-i-d1[i]<0)
            {
                t=0;
                break;
            }
            t*=(n-i-d1[i]);
            t%=M;
        }

        cntj-=t;
        cntj%=M;
        cntj+=M;
        cntj%=M;

        cnt+=cntj;
        cnt%=M;
    }

    // dbg(cnt);

    int ans=cnt;
    ans*=binpow(fact[n]);
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