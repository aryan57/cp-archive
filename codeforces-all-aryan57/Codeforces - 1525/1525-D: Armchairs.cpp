//https://codeforces.com/contest/1525/problem/D

/*
    // blog used
    author : aryan57
    created : 17-May-2021 09:58:37 IST
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
const int INF = 1e9;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

void solve_LOG()
{
    int n;
    cin>>n;

    vector <int> v(n+1);
    vector <int> pos;
    pos.push_back(0);
    F(i,1,n)
    {
        cin>>v[i];
        if(v[i])
        {
            pos.push_back(i);
        }
    }
    int k=sz(pos)-1;
    vector< vector<int> > dp(n+1,vector <int> (n+1,INF));
    dp[0][0]=0;
    // dbg(dp[0][0]);
    // dbg(dp[0][1]);
    F(i,1,n)
    {
        dp[i][0]=0;
        F(j,1,k)
        {
            dp[i][j]=min(dp[i][j],dp[i-1][j]);
            if(v[i]==0)
            {
                dp[i][j]=min(dp[i][j],dp[i-1][j-1]+abs(pos[j]-i));
            }

            // dbg(i,j,dp[i][j]);
        }
    }

    cout<<dp[n][k];

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