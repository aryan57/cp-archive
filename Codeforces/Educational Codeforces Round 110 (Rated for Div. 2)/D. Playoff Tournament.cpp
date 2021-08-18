/*
	group : Codeforces - Educational Codeforces Round 110 (Rated for Div. 2)
	name : D. Playoff Tournament.cpp
	srcPath : /home/aryan/Documents/cp/D_Playoff_Tournament.cpp
	url : https://codeforces.com/contest/1535/problem/D
*/
/*
    author : aryan57
    created : 05-June-2021 02:38:53 IST
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

const int mxn = 6e5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector <int> val(mxn,1);
string s;
int k;
int n;
int dfs(int u)
{
    if(u>n)return 1;

    int l=dfs(2*u);
    int r=dfs(2*u+1);

    if(s[u]=='1')
    {
        val[u]=l;
    }
    if(s[u]=='0')
    {
        val[u]=r;
    }
    if(s[u]=='?')
    {
        val[u]=l+r;
    }

    return val[u];
}

void solve_LOL()
{
    cin>>k;
    cin>>s;
    n=sz(s);
    F(i,0,n)val[i]=0;
    reverse(all(s));
    s='#'+s;

    dfs(1);


    int q;
    cin>>q;
    while (q--)
    {
        int i;
        char c;
        cin>>i;
        cin>>c;
        s[n-i+1]=c;
        int cur=n-i+1;

        while (cur)
        {
            if(s[cur]=='1')
            {
                val[cur]=val[2*cur];
            }
            if(s[cur]=='0')
            {
                val[cur]=val[2*cur+1];
            }
            if(s[cur]=='?')
            {
                val[cur]=val[2*cur]+val[2*cur+1];
            }
            cur/=2;
        }
        cout<<val[1];
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}