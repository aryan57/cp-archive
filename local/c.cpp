/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Documents/cp/c.cpp
	url : /home/aryan/Documents/cp/c.cpp
*/
/*
    author : aryan57
    created : 12-July-2021 12:43:24 IST
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
// https://atcoder.github.io/ac-library/production/document_en/segtree.html

int binary_operation(int a,int b)
{
    return a+b;
}

int identity_element()
{
    return 0;
}

int target;
bool check_function(int v)
{
    return v<=target;
}


void solve()
{
    int n;
    cin>>n;

    vector<pair<int,int> > v(n+1);

    for(int i=1;i<=n;i++)
    {
        cin>>v[i].first;
        v[i].second=i;
    }

    // we will sort the initial cost of toys and in each query change the cost of damaged toys to 0
    // so answer for each query will be the no. of 1's in the second segment tree in the maximum length prefix having sum<=C
    sort(v.begin()+1,v.end()); // sort from index '1' to 'n'

    vector <int> new_index(n+1);

    for(int i=1;i<=n;i++)
        new_index[v[i].second]=i;
    
    /*
        new_index[i] will give the new postion of an index after sorting

        for example:
        initial array: [8,6,5,7]
        sorted array: [5,6,7,8]

        new_index[1]=4
        new_index[2]=2
        new_index[3]=1
        new_index[4]=3
    */

    // this tree will contain cost of toys 
    segtree<int,binary_operation,identity_element> tree(n+1);

    // this will be tree of 0s and 1s and we will count the no. not-damaged toys in a range
    segtree<int,binary_operation,identity_element> count_tree(n+1);

    for(int i=1;i<=n;i++)
    {
        tree.set(i,v[i].first);
        count_tree.set(i,1);
    }

    int q;
    cin>>q;
    while (q--)
    {
        int c,k;
        cin>>c>>k;
        vector <int> rem(k+1);
        for(int i=1;i<=k;i++)
        {
            cin>>rem[i];
            tree.set(new_index[rem[i]],0);
            count_tree.set(new_index[rem[i]],0);
        }

        target=c;

        int r=tree.max_right<check_function>(1);

        cout<<count_tree.prod(1,r)<<"\n";

        // changing everythin back to initial values as queries are independent
        for(int i=1;i<=k;i++)
        {
            tree.set(new_index[rem[i]],v[new_index[rem[i]]].first);
            count_tree.set(new_index[rem[i]],1);
        }

    }
    
}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t=1;
    cin>>_t;
    while (_t--)solve();
    
    return 0;
}