//https://codeforces.com/contest/1513/problem/D

/*
    // tut used
    // credits: @yash_daga
    author : Aryan Agarwal, IIT Kharagpur
    created : 12-April-2021 09:23:41 IST
*/

#include <bits/stdc++.h>
using namespace std;

void __print(int x) {cerr << x;}
void __print(long x) {cerr << x;}
void __print(long long x) {cerr << x;}
void __print(unsigned x) {cerr << x;}
void __print(unsigned long x) {cerr << x;}
void __print(unsigned long long x) {cerr << x;}
void __print(float x) {cerr << x;}
void __print(double x) {cerr << x;}
void __print(long double x) {cerr << x;}
void __print(char x) {cerr << '\'' << x << '\'';}
void __print(const char *x) {cerr << '\"' << x << '\"';}
void __print(const string &x) {cerr << '\"' << x << '\"';}
void __print(bool x) {cerr << (x ? "true" : "false");}

template<typename T, typename V>
void __print(const pair<T, V> &x) {cerr << '{'; __print(x.first); cerr << ','; __print(x.second); cerr << '}';}
template<typename T>
void __print(const T &x) {int f = 0; cerr << '{'; for (auto &i: x) cerr << (f++ ? "," : ""), __print(i); cerr << "}";}
void _print() {cerr << "]\n";}
template <typename T, typename... V>
void _print(T t, V... v) {__print(t); if (sizeof...(v)) cerr << ", "; _print(v...);}

#ifndef ONLINE_JUDGE
#define dbg(x...) cerr << "[" << #x << "] = ["; _print(x)
#else
#define dbg(x...)
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

struct Edge {
    int u, v, weight;
    bool operator<(Edge const& other) {
        return weight < other.weight;
    }
};

/* 
    dsu d(int n)
    // It creates an undirected graph with n vertices and 0 edges.
    // 0<=n<=1e8
    // O(n)

    int d.merge(int a, int b)
    // It adds an edge (a, b)
    // If the vertices a and b were in the same connected component, it returns the representative of this connected component. Otherwise, it returns the representative of the new connected component.
    // 0<=a<n   0<=b<n
    // O(α(n)) amortized

    bool d.same(int a, int b)
    // Returns whether the vertices a and b are in the same connected component
    // 0<=a<n   0<=b<n
    // O(α(n)) amortized

    int d.leader(int a)
    // Returns the representative of the connected component that contains the vertex a
    // 0<=a<n
    // O(α(n)) amortized

    int d.size(int a)
    // Returns the size of the connected component that contains the vertex a.
    // 0<=a<n
    // O(α(n)) amortized

    vector<vector<int>> d.groups()
    // Returns the list of the "list of the vertices in a connected component"
    // O(n)
*/
struct dsu {
  public:
    dsu() : _n(0) {}
    dsu(int n) : _n(n), parent_or_size(n, -1) {}

    int merge(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        int x = leader(a), y = leader(b);
        if (x == y) return x;
        if (-parent_or_size[x] < -parent_or_size[y]) std::swap(x, y);
        parent_or_size[x] += parent_or_size[y];
        parent_or_size[y] = x;
        return x;
    }

    bool same(int a, int b) {
        assert(0 <= a && a < _n);
        assert(0 <= b && b < _n);
        return leader(a) == leader(b);
    }

    int leader(int a) {
        assert(0 <= a && a < _n);
        if (parent_or_size[a] < 0) return a;
        return parent_or_size[a] = leader(parent_or_size[a]);
    }

    int size(int a) {
        assert(0 <= a && a < _n);
        return -parent_or_size[leader(a)];
    }

    std::vector<std::vector<int>> groups() {
        std::vector<int> leader_buf(_n), group_size(_n);
        for (int i = 0; i < _n; i++) {
            leader_buf[i] = leader(i);
            group_size[leader_buf[i]]++;
        }
        std::vector<std::vector<int>> result(_n);
        for (int i = 0; i < _n; i++) {
            result[i].reserve(group_size[i]);
        }
        for (int i = 0; i < _n; i++) {
            result[leader_buf[i]].push_back(i);
        }
        result.erase(
            std::remove_if(result.begin(), result.end(),
                           [&](const std::vector<int>& v) { return v.empty(); }),
            result.end());
        return result;
    }

  private:
    int _n;
    // root node: -1 * component size
    // otherwise: parent
    std::vector<int> parent_or_size;
};

void solve_LOL()
{
    int n,p;
    cin>>n>>p;
    vector<Edge> edges;
    int a[n];
    F(i,0,n-1)
    {
        cin>>a[i];
        if(i)
        {
            Edge e;
            e.weight=p;
            e.u=i-1;
            e.v=i;
            edges.push_back(e);
        }
    }
    

    F(i,0,n-1)
    {
        int j;

        j=i+1;
        while(j<n && a[j]%a[i]==0)
        {
            Edge e;
            e.weight=a[i];
            e.u=i;
            e.v=j;
            edges.push_back(e);
            j++;

            if(a[j]==a[i])break;
        }
        j=i-1;
        while(j>=0 && a[j]%a[i]==0)
        {
            Edge e;
            e.weight=a[i];
            e.u=i;
            e.v=j;
            edges.push_back(e);
            j--;

            if(a[j]==a[i])break;
        }
    }

    int cost = 0;

    sort(edges.begin(), edges.end());

    dsu d(n);

    for (Edge e : edges) {
        if (!d.same(e.u,e.v)) {
            cost += e.weight;
            d.merge(e.u,e.v);
        }
    }

    cout<<cost;
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
    // defualt mxn_sieve = 1e5
    sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
    // default [L,R] = [1,1e5]
    segmented_sieve();
#endif
#ifdef ARYAN_FACT
    // default mxn_fact = 1e5
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