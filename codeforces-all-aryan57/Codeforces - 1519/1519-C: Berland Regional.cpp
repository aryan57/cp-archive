//https://codeforces.com/contest/1519/problem/C

/*
    author : aryan57
    created : 29-April-2021 20:44:24 IST
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


    vector <int> adj[n];

    int u[n];

    F(i,0,n-1)
    {
        cin>>u[i];
        u[i]--;
    }
    int s[n];

    F(i,0,n-1)
    {
        cin>>s[i];
        adj[u[i]].push_back(s[i]);
    }

    vector <int> ans(n);
    F(i,0,n-1)
    {
        if(adj[i].empty())continue;
        sort(all(adj[i]),greater<int> ());
        int pre[sz(adj[i])];
        pre[0]=adj[i][0];

        F(j,1,sz(adj[i])-1)
        {
            pre[j]=pre[j-1]+adj[i][j];
        }

        int tot=sz(adj[i]);

        F(k,1,n)
        {
            if(tot/k==0 || k*(tot/k)-1<0)break;

            ans[k-1]+=pre[k*(tot/k)-1];
        }
    }

    for(int x : ans)cout<<x<<" ";
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
    cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOL();
    }
    return 0;
}