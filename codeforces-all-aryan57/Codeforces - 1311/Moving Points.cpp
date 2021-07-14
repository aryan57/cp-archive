/*
    // sol used...
    author : Aryan Agarwal, IIT KGP
    created : 25-December-2020 11:48:19 IST
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

template <class T> struct fenwick_tree {

  public:

    // Ex. -> fenwick_tree<long long> fw(n);
    // It creates an array a0, a1, ..., a_{n-1} of length n.
    // All the elements are initialized to 0.
    fenwick_tree() : _n(0) {}
    fenwick_tree(int n) : _n(n), data(n) {}

    // Ex. -> fw.add(0,10);
    // It processes a[p]+=x
    void add(int p, T x) {
        assert(0 <= p && p < _n);
        p++;
        while (p <= _n) {
            data[p - 1] += (x);
            p += p & -p;
        }
    }

    // Ex. -> fw.sum(0,n);
    // It returns a[l]+a[l+1]+....+a[r-1]
    T sum(int l, int r) {
        assert(0 <= l && l <= r && r <= _n);
        return sum(r) - sum(l);
    }

  private:

    int _n;
    vector<T> data;

    // It returns a[0]+a[1]+....+a[r-1]
    // However it is a private function,
    // so no need to worry
    T sum(int r) {
        T s = 0;
        while (r > 0) {
            s += data[r - 1];
            r -= r & -r;
        }
        return s;
    }
};

void solve_LOG()
{
    int n;
    cin>>n;

    vector<pair<int,int> > v(n);
    vector <int> velo(n);

    F(i,0,n-1)
    {
        cin>>v[i].X;
    }
    F(i,0,n-1)
    {
        cin>>v[i].Y;
        velo[i]=v[i].Y;
    }

    sort(all(v));
    sort(all(velo));

    fenwick_tree <int> cnt(n),x(n);
    int ans=0;
    F(i,0,n-1)
    {
        int pos=lower_bound(all(velo),v[i].Y)-velo.begin();
        ans+=v[i].X*cnt.sum(0,pos+1)-x.sum(0,pos+1);
        // dbg(ans,pos,v[i].Y,cnt.sum(0,pos+1),x.sum(0,pos+1));
        cnt.add(pos,1);
        x.add(pos,v[i].X);
    }

    cout<<ans;

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