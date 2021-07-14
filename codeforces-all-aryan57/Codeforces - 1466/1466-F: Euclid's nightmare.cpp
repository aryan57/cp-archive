//https://codeforces.com/contest/1466/problem/F

/*
    // tut used...
    author : Aryan Agarwal, IIT KGP
    created : 31-December-2020 03:16:41 IST
*/

#include <bits/stdc++.h>
using namespace std;
#define int long long

const int mxn = 1e5;
const long long INF = 2e18;
const int32_t M = 1000000007; /*more than (10)^9*/ /*7 + 1e9*/
// const int32_t M = 998244353; /*less than (10)^9*/   /*1 + 7*17*(2)^23*/
const long double pie = acos(-1);

#define X first
#define Y second
#define pb push_back
#define sz(a) ((int)(a).size())
#define all(a) (a).begin(), (a).end()
#define F(i, a, b) for (int i = a; i <= b; i++)
#define RF(i, a, b) for (int i = a; i >= b; i--)

#define dbg(...) __f(#__VA_ARGS__, __VA_ARGS__)
template <typename Arg1>
void __f(const char* name, Arg1&& arg1){
  cerr << name << " : " << arg1 << std::endl;
}
template <typename Arg1, typename... Args>
void __f(const char* names, Arg1&& arg1, Args&&... args){
  const char* comma = strchr(names + 1, ',');cerr.write(names, comma - names) << " : " << arg1<<" | ";__f(comma+1, args...);
}

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

/*
    Binary Exponentiation
    // (a^b)%m
    // O(logb)
    // modInverse(a) = binpow(a, phi(n)-1, n)
    // If n is prime, phi(n)=n-1
*/
int binpow(int a, int b=M-2, int m=M) {
    a %= m;
    int res = 1;
    while (b > 0) {
        if (b & 1)
            res = res * a % m;
        a = a * a % m;
        b >>= 1;
    }
    return res;
}

void solve_LOG()
{
    int n,m;
    cin>>n>>m;

    dsu d(m+2);
    vector <int> ans;
    F(i,1,n)
    {
        int k;
        cin>>k;
        int l,r=m+1;
        cin>>l;
        if(k==2)cin>>r;

        if(!d.same(l,r))
        {
            d.merge(l,r);
            ans.pb(i);
        }

    }

    cout<<binpow(2,sz(ans))<<" "<<sz(ans);
    cout<<"\n";
    for(int x : ans)cout<<x<<" ";
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
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
    // cin>>_t;
    for (int i=1;i<=_t;i++)
    {
        // cout<<"Case #"<<i<<": ";
        solve_LOG();
    }
    return 0;
}