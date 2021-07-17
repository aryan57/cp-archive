/*
	group : Codeforces - Educational Codeforces Round 74 (Rated for Div. 2)
	name : E. Keyboard Purchase.cpp
	srcPath : /home/aryan/Documents/cp/E_Keyboard_Purchase.cpp
	url : https://codeforces.com/contest/1238/problem/E
*/
/*
    author : aryan57
    created : 17-July-2021 17:18:49 IST
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
    int n,m;
    cin>>n>>m;

    string s;
    cin>>s;

    int cnt[m][m];

    F(i,1,n-1)
    {
        cnt[s[i]-'a'][s[i-1]-'a']++;
        cnt[s[i-1]-'a'][s[i]-'a']++;
    }

    int tot=(1<<m);
    vector <int> dp(tot,INF);
    dp[0]=0;

    vector <int> popcount(tot,0);

    F(i,1,tot-1)
    {
        popcount[i] = popcount[i&(i-1)] + 1;
    }

    F(mask,0,tot-1)
    {
        

        F(a,0,m-1)
        {
            if((mask>>a)&1)continue;
            int s1=0;
        int s2=0;
            F(b,0,m-1)
            {
                if( (mask>>b)&1 )
                {
                    s1+=cnt[a][b];
                }
                else
                {
                    s2+=cnt[a][b];
                }
            }
            int newmask = mask | (1<<a);

            dp[newmask] = min(dp[newmask],dp[mask] + popcount[mask]*(s1-s2));
        }
    }

    cout<<dp[tot-1];
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
//	parsed : 17-July-2021 17:18:39 IST