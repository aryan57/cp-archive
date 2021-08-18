/*
	group : HackerRank - GOC-CDC Series #12
	name : Save the Hostage.cpp
	srcPath : /home/aryan/Documents/cp/Save_the_Hostage.cpp
	url : https://www.hackerrank.com/contests/goc-cdc-series-12/challenges/save-the-hostage
*/
/*
    author : aryan57
    created : 10-July-2021 16:24:11 IST
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

const int mxn = 1e5+5;
const long long INF = 2e18;
const int32_t M = 1000000007;
// const int32_t M = 998244353;
const long double pie = acos(-1);

vector < pair <int,int>  > adj[mxn+1];
vector < pair <int,int>  > adj2[mxn+1];

// O(nlogn+mlogn)
// Dijkstra on sparse graphs
void dijkstra(int s, vector<int> & d) {

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                /*
                    q.erase({d[to], to});

                    no need to erase, let the old pair be in the priority_queue,
                    since we are always accessing the smallest pair,
                    this old pair will never be used.
                */
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

// O(nlogn+mlogn)
// Dijkstra on sparse graphs
void dijkstra2(int s, vector<int> & d) {

    d[s] = 0;
    using pii = pair<int, int>;
    priority_queue<pii, vector<pii>, greater<pii>> q;
    q.push({0, s});
    while (!q.empty()) {
        int v = q.top().second;
        int d_v = q.top().first;
        q.pop();
        if (d_v != d[v])
            continue;

        for (auto edge : adj2[v]) {
            int to = edge.first;
            int len = edge.second;

            if (d[v] + len < d[to]) {
                /*
                    q.erase({d[to], to});

                    no need to erase, let the old pair be in the priority_queue,
                    since we are always accessing the smallest pair,
                    this old pair will never be used.
                */
                d[to] = d[v] + len;
                q.push({d[to], to});
            }
        }
    }
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;

    int s,d;
    cin>>s>>d;

    F(i,1,m)
    {
        int u,v,t;
        cin>>u>>v>>t;
        adj[u].push_back({v,t});
        adj2[v].push_back({u,t});
    }

    vector <int> d1(n+1,INF);
    vector <int> d2(n+1,INF);

    dijkstra(s,d1);
    dijkstra2(d,d2);

    int ans=INF;

    F(i,1,n)
    {
        if(d1[i]+d2[i]+1>=INF)
        {
            cout<<"-1\n";
            return;
        }
        // dbg(i,d1[i],d2[i]);
        ans=min(ans,d1[i]+d2[i]+1);
    }

    

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
//	parsed : 10-July-2021 16:23:04 IST