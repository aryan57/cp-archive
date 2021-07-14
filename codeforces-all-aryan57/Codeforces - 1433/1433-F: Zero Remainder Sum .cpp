//https://codeforces.com/contest/1433/problem/F

/*
    // solution used
    author : aryan57
    created : 20-April-2021 19:28:47 IST
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

// #define int long long
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

int dp[75][75][75][75];

void solve_LOG()
{
    int n,m,k;
    cin>>n>>m>>k;
    

    F(i,0,74)
    {
        F(j,0,74)
        {
            F(k,0,74)
            {
                F(l,0,74)
                {
                    dp[i][j][k][l]=INT32_MIN;
                }
            }
        }
    }

    dp[0][0][0][0]=0;

    int g[n][m];
    F(i,0,n-1)
    {
        F(j,0,m-1)
        {
            cin>>g[i][j];
        }
    }


    F(x,0,n-1)
    {
        F(y,0,m-1)
        {
            F(cnt,0,m)
            {
                F(rem,0,k-1)
                {
                    if(y!=m-1)
                    {
                        dp[x][y+1][cnt][rem]=max(dp[x][y+1][cnt][rem],dp[x][y][cnt][rem]);
                        
                        if(cnt<m/2)
                            dp[x][y+1][cnt+1][(rem+g[x][y])%k]=max(dp[x][y+1][cnt+1][(rem+g[x][y])%k],dp[x][y][cnt][rem]+g[x][y]);
                    }
                    else
                    {
                        dp[x+1][0][0][rem]=max(dp[x+1][0][0][rem],dp[x][y][cnt][rem]);
                        
                        if(cnt<m/2)
                            dp[x+1][0][0][(rem+g[x][y])%k]=max(dp[x+1][0][0][(rem+g[x][y])%k],dp[x][y][cnt][rem]+g[x][y]);
                    }
                }
            }
        }
    }


    cout<<max(0,dp[n][0][0][0]);



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