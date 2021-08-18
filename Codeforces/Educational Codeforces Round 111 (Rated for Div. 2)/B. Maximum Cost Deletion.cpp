/*
	group : Codeforces - Educational Codeforces Round 111 (Rated for Div. 2)
	name : B. Maximum Cost Deletion.cpp
	srcPath : /home/aryan/Documents/cp/B_Maximum_Cost_Deletion.cpp
	url : https://codeforces.com/contest/1550/problem/B
*/
/*
    author : aryan57
    created : 14-July-2021 20:34:05 IST
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
    string s;
    int n,a,b;
    cin>>n>>a>>b;
    cin>>s;

    s='#'+s+'#';
    vector <int> v;

    int prev=s[1];
    int z=0;
    int o=0;
    F(i,2,n+1)
    {
        if(s[i]!=prev)
        {
            if(prev=='0')z++;
            else o++;
            prev=s[i];
        }
    }

    if(b>=0)
    {
        cout<<(a+b)*n;
        cout<<"\n";
    }
    else
    {
        int ans=-INF;
        ans=max(ans,a*n + b*(z+1));
        ans=max(ans,a*n + b*(o+1));

        cout<<ans;
        cout<<"\n";
    }
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
//	parsed : 14-July-2021 20:31:11 IST