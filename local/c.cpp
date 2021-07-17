/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Documents/cp/c.cpp
	url : /home/aryan/Documents/cp/c.cpp
*/
/*
    author : aryan57
    created : 15-July-2021 20:45:41 IST
*/
#include <bits/stdc++.h>
using namespace std;

template <class S, S (*op)(S, S), S (*e)()> struct segtree {
  public:
    segtree() : segtree(0) {}
    explicit segtree(int n) : segtree(std::vector<S>(n, e())) {}
    explicit segtree(const std::vector<S>& v) : _n((int)(v.size())) {
        log = segtree::ceil_pow2(_n);
        size = 1 << log;
        d = std::vector<S>(2 * size, e());
        for (int i = 0; i < _n; i++) d[size + i] = v[i];
        for (int i = size - 1; i >= 1; i--) {
            update(i);
        }
    }

    void set(int p, S x) {
        assert(0 <= p && p < _n);
        p += size;
        d[p] = x;
        for (int i = 1; i <= log; i++) update(p >> i);
    }

    S get(int p) const {
        assert(0 <= p && p < _n);
        return d[p + size];
    }

    S prod(int l, int r) const {
        assert(0 <= l && l <= r && r <= _n);
        S sml = e(), smr = e();
        l += size;
        r += size;

        while (l < r) {
            if (l & 1) sml = op(sml, d[l++]);
            if (r & 1) smr = op(d[--r], smr);
            l >>= 1;
            r >>= 1;
        }
        return op(sml, smr);
    }

    S all_prod() const { return d[1]; }

    template <bool (*f)(S)> int max_right(int l) const {
        return max_right(l, [](S x) { return f(x); });
    }
    template <class F> int max_right(int l, F f) const {
        assert(0 <= l && l <= _n);
        assert(f(e()));
        if (l == _n) return _n;
        l += size;
        S sm = e();
        do {
            while (l % 2 == 0) l >>= 1;
            if (!f(op(sm, d[l]))) {
                while (l < size) {
                    l = (2 * l);
                    if (f(op(sm, d[l]))) {
                        sm = op(sm, d[l]);
                        l++;
                    }
                }
                return l - size;
            }
            sm = op(sm, d[l]);
            l++;
        } while ((l & -l) != l);
        return _n;
    }

    template <bool (*f)(S)> int min_left(int r) const {
        return min_left(r, [](S x) { return f(x); });
    }
    template <class F> int min_left(int r, F f) const {
        assert(0 <= r && r <= _n);
        assert(f(e()));
        if (r == 0) return 0;
        r += size;
        S sm = e();
        do {
            r--;
            while (r > 1 && (r % 2)) r >>= 1;
            if (!f(op(d[r], sm))) {
                while (r < size) {
                    r = (2 * r + 1);
                    if (f(op(d[r], sm))) {
                        sm = op(d[r], sm);
                        r--;
                    }
                }
                return r + 1 - size;
            }
            sm = op(d[r], sm);
        } while ((r & -r) != r);
        return 0;
    }

  private:
    int _n, size, log;
    std::vector<S> d;

    void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }

    // @param n `0 <= n`
    // @return minimum non-negative `x` s.t. `n <= 2**x`
    int ceil_pow2(int n) {
        int x = 0;
        while ((1U << x) < (unsigned int)(n)) x++;
        return x;
    }

};

int binary_operation(int a,int b)
{
    return max(a,b);
}

int identity_element()
{
    return INT32_MIN;
}



struct node {
    int val,mn_ind,mx_ind;
};
struct query {
    int l,r,index;
};

void shrink(vector <node> &v,vector< vector<int> > &f)
{
    if(v.empty())return;
    
    int n=v.size();
    
    for(int i=0;i<n;i++) {
        int l=v[i].mn_ind;
        int r=v[i].mx_ind;
        assert(f[l][r]==-1);
        f[l][r]=v[i].val;
    }

    for(int i=0;i<n-1;i++)
    {
        v[i].val ^= v[i+1].val;
        v[i].mn_ind = min(v[i].mn_ind,v[i+1].mn_ind);
        v[i].mx_ind = max(v[i].mx_ind,v[i+1].mx_ind);
        
    }

    v.pop_back();
    shrink(v,f);
}

bool comp(query a,query b) {
    return a.r<b.r;
}

void solve()
{
    int n;
    cin>>n;
    vector <node> v(n);

    for(int i=0;i<n;i++)
    {
        cin>>v[i].val;
        v[i].mn_ind=v[i].mx_ind=i;
    }

    vector< vector<int> > f(n,vector <int> (n,-1));
    shrink(v,f);
    // now we know, value of function 'f' for each subarray
    // we will solve the problem offline
    // sort all the queries, and implment a segtree
    
    int Q;
    cin>>Q;
    vector<query> queries(Q);
    int ind=0;
    for(query &q : queries){
        cin>>q.l>>q.r;
        q.l--;
        q.r--;
        q.index=ind++;
    }

    sort(queries.begin(),queries.end(),comp); // sort acccording to 'r' values

    segtree<int,binary_operation,identity_element> tree(n);

    vector <int> ans(Q);
    int start=0;
    for(query q : queries) {
        
        for(int r=start;r<=q.r;r++) {
            for(int l=0;l<=r;l++) {
                tree.set(l,max(tree.get(l),f[l][r]));
            }
        }

        ans[q.index] = tree.prod(q.l,q.r+1); // get maximum in range [l,r+1) or [l,r]
        start=q.r+1;
    }

    for(int x : ans)cout<<x<<" ";
    cout<<"\n";

}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    solve();
    
    return 0;
}