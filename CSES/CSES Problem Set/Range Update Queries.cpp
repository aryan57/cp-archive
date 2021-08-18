/*
	group : CSES - CSES Problem Set
	name : Range Update Queries.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Range_Update_Queries.cpp
	url : https://cses.fi/problemset/task/1651
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.08.2021 21:31:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template <class S,
		  S (*op)(S, S),
		  S (*e)(),
		  class F,
		  S (*mapping)(F, S),
		  F (*composition)(F, F),
		  F (*id)()>
struct lazy_segtree {
  public:
	lazy_segtree() : lazy_segtree(0) {}
	explicit lazy_segtree(int n) : lazy_segtree(std::vector<S>(n, e())) {}
	explicit lazy_segtree(const std::vector<S>& v) : _n((int)(v.size())) {
		log = ceil_pow2(_n);
		size = 1 << log;
		d = std::vector<S>(2 * size, e());
		lz = std::vector<F>(size, id());
		for (int i = 0; i < _n; i++) d[size + i] = v[i];
		for (int i = size - 1; i >= 1; i--) {
			update(i);
		}
	}

	void set(int p, S x) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = x;
		for (int i = 1; i <= log; i++) update(p >> i);
	}

	S get(int p) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		return d[p];
	}

	S prod(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		if (l == r) return e();

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		S sml = e(), smr = e();
		while (l < r) {
			if (l & 1) sml = op(sml, d[l++]);
			if (r & 1) smr = op(d[--r], smr);
			l >>= 1;
			r >>= 1;
		}

		return op(sml, smr);
	}

	S all_prod() { return d[1]; }

	void apply(int p, F f) {
		assert(0 <= p && p < _n);
		p += size;
		for (int i = log; i >= 1; i--) push(p >> i);
		d[p] = mapping(f, d[p]);
		for (int i = 1; i <= log; i++) update(p >> i);
	}
	void apply(int l, int r, F f) {
		assert(0 <= l && l <= r && r <= _n);
		if (l == r) return;

		l += size;
		r += size;

		for (int i = log; i >= 1; i--) {
			if (((l >> i) << i) != l) push(l >> i);
			if (((r >> i) << i) != r) push((r - 1) >> i);
		}

		{
			int l2 = l, r2 = r;
			while (l < r) {
				if (l & 1) all_apply(l++, f);
				if (r & 1) all_apply(--r, f);
				l >>= 1;
				r >>= 1;
			}
			l = l2;
			r = r2;
		}

		for (int i = 1; i <= log; i++) {
			if (((l >> i) << i) != l) update(l >> i);
			if (((r >> i) << i) != r) update((r - 1) >> i);
		}
	}

	template <bool (*g)(S)> int max_right(int l) {
		return max_right(l, [](S x) { return g(x); });
	}
	template <class G> int max_right(int l, G g) {
		assert(0 <= l && l <= _n);
		assert(g(e()));
		if (l == _n) return _n;
		l += size;
		for (int i = log; i >= 1; i--) push(l >> i);
		S sm = e();
		do {
			while (l % 2 == 0) l >>= 1;
			if (!g(op(sm, d[l]))) {
				while (l < size) {
					push(l);
					l = (2 * l);
					if (g(op(sm, d[l]))) {
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

	template <bool (*g)(S)> int min_left(int r) {
		return min_left(r, [](S x) { return g(x); });
	}
	template <class G> int min_left(int r, G g) {
		assert(0 <= r && r <= _n);
		assert(g(e()));
		if (r == 0) return 0;
		r += size;
		for (int i = log; i >= 1; i--) push((r - 1) >> i);
		S sm = e();
		do {
			r--;
			while (r > 1 && (r % 2)) r >>= 1;
			if (!g(op(d[r], sm))) {
				while (r < size) {
					push(r);
					r = (2 * r + 1);
					if (g(op(d[r], sm))) {
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
	std::vector<F> lz;

	void update(int k) { d[k] = op(d[2 * k], d[2 * k + 1]); }
	void all_apply(int k, F f) {
		d[k] = mapping(f, d[k]);
		if (k < size) lz[k] = composition(f, lz[k]);
	}
	void push(int k) {
		all_apply(2 * k, lz[k]);
		all_apply(2 * k + 1, lz[k]);
		lz[k] = id();
	}

	// @param n `0 <= n`
	// @return minimum non-negative `x` s.t. `n <= 2**x`
	int ceil_pow2(int n) {
		int x = 0;
		while ((1U << x) < (unsigned int)(n)) x++;
		return x;
	}
};

using S=int;
using F=int;

// associativity: (a.b).c = a.(b.c) for all a, b, c in S
S op(S a,S b)
{
	return a+b;
}
// existence of the identity element, a.e = e.a = a for all a in S
S e()
{
	return 0;
}

// f(x.y)=f(x).f(y) holds for all f in F and x, y in S.
S mapping(F f, S x)
{
	return x+f; // if you want a[i] += 1 , for [l,l+1,...r) , use tree.apply(l,r,1)
}
// F is closed under composition, i.e., (f of g) belongs to F is true for all f, g in F
F composition(F f, F g)
{
	return f+g; // if you want a[i] += 1 , for [l,l+1,...r) , use tree.apply(l,r,1)
}
// identity map is the map that satisfies id(x) = x for all x in S
F id()
{
	return 0;
}
// lazy_segtree<S,op,e,F,mapping,composition,id> tree(10);

void solve()
{
	int n,q;
	cin>>n>>q;
	vector<int> v(n);
	for(int &x : v)cin>>x;

	lazy_segtree<S,op,e,F,mapping,composition,id> tree(v);

	while(q--)
	{
		int id;
		cin>>id;
		if(id==1){
			int a,b,u;
			cin>>a>>b>>u;
			--a;--b;
			tree.apply(a,b+1,u);
		}else{
			int k;
			cin>>k;
			--k;
			cout<<tree.get(k)<<"\n";
		}
	}

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 02-August-2021 21:30:23 IST