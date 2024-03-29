/*
	group : AtCoder - AtCoder Beginner Contest 204
	name : D - Cooking.cpp
	srcPath : /home/aryan/Documents/cp/D_Cooking.cpp
	url : https://atcoder.jp/contests/ABC204/tasks/abc204_d
*/
/*
    author : aryan57
    created : 06-June-2021 17:39:51 IST
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
    vector <int> t(n+1);
    int tot=0;
    F(i,1,n)
    {
        cin>>t[i];
        tot+=t[i];
    }

    vector< vector<bool> > dp(n+1,vector <bool> (1000*n+1,false));
    dp[0][0]=true;

    F(i,1,n)
    {
        F(j,0,1000*i)
        {
            dp[i][j] = dp[i-1][j]|dp[i][j];
            if(j-t[i]>=0)
            dp[i][j] = dp[i-1][j-t[i]]|dp[i][j];
        }
    }

    int mn=INF;

    F(j,0,1000*n)
    {
        if(!dp[n][j])continue;
        assert(j<=tot);
        mn=min({mn,max(j,tot-j)});
    }

    cout<<mn;

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
//	parsed : 06-June-2021 17:39:38 IST