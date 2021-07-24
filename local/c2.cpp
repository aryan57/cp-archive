/*
	group : local
	name : c2.cpp
	srcPath : /home/aryan/Documents/cp/c2.cpp
	url : /home/aryan/Documents/cp/c2.cpp
*/
/*
    author : aryan57
    created : 24-July-2021 15:55:34 IST
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

    int g[n+1][m+1]={};
    int len[n+1][m+1]={};
    int c[n+1][m+1]={};

    int ans=0;

    F(i,1,n)
    {
        int pre[m+1];
        int suf[m+1];
        int last=0;
        F(j,1,m)
        {
            cin>>g[i][j];
            if(g[i][j]==0)ans--;
            if(g[i][j])last=j;
            pre[j]=last;
        }
        last=m+1;
        RF(j,m,1)
        {
            if(g[i][j])last=j;

            len[i][j]=max({0ll,min(last-j,j-pre[j])});

            int cc=1+i-len[i][j];
            if(cc<=0)cc=1;
            if(i>1)cc=max(cc,c[i-1][j]);

            c[i][j]=cc;

            int z=i-c[i][j]+1;
            z=max(z,0ll);
            ans+=z;
        }
    }

    cout<<ans;
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