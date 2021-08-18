/*
	group : HackerRank - GOC-CDC Series #12
	name : Array Partition 2.cpp
	srcPath : /home/aryan/Documents/cp/Array_Partition_2.cpp
	url : https://www.hackerrank.com/contests/goc-cdc-series-12/challenges/array-partition-2-1
*/
/*
    author : aryan57
    created : 10-July-2021 17:15:02 IST
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

void solve_LOL()
{
    int n;
    cin>>n;

    vector <int> a(n+1);
    int tot=0;
    F(i,1,n)
    {
        cin>>a[i];
        tot+=a[i];
        a[i]+=1001;
    }
    int mx_sum=2e5;
    vector< vector<bool> > dp(n+1,vector <bool> (mx_sum+1,false));
    vector< vector<int> > cnt(n+1,vector <int> (mx_sum+1,0));
    dp[0][0]=true;
    cnt[0][0]=0;
    int ans=-INF;
    F(i,1,n)
    {
        F(s,0,mx_sum)
        {
            if(dp[i-1][s])
            {
                dp[i][s]=true;
                cnt[i][s]=cnt[i-1][s];
            }
            if(s>=a[i] && dp[i-1][s-a[i]])
            {
                dp[i][s]=true;
                cnt[i][s]=cnt[i-1][s-a[i]]+1;
            }

            if(dp[i][s])
            {
                int sum=s-1001*cnt[i][s];
                ans=max(ans,(tot-sum)*(sum));
            }
        }
    }

    cout<<ans;cout<<"\n";
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}