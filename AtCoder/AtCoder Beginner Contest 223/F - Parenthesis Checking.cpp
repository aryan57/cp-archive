/*
	group : AtCoder - AtCoder Beginner Contest 223
	name : F - Parenthesis Checking.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Parenthesis_Checking.cpp
	url : https://atcoder.jp/contests/abc223/tasks/abc223_f
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.10.2021 12:00:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

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

int inf = 1e9;

// associativity: (a.b).c = a.(b.c) for all a, b, c in S
S op(S a,S b)
{
	return min(a,b);
}
// existence of the identity element, a.e = e.a = a for all a in S
S e()
{
	return inf;
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

/*
	It is the data structure for monoids i.e., the algebraic structure that satisfies the following properties :
		associativity: (a⋅b)⋅c = a⋅(b⋅c) for all a,b,c ∈ S
		existence of the identity element: a⋅e = e⋅a = a for all a ∈ S

	(1) segtree<S, binary_operation, identity_element> seg(int n)
	(2) segtree<S, binary_operation, identity_element> seg(vector<S> v)
		(1): It creates an array a of length n. All the elements are initialized to identity_element().
		(2): It creates an array a of length n = v.size(), initialized to v.
		0≤n≤10**8
		O(n)

	void seg.set(int p, S x)
		It assigns x to a[p]
		0≤p<n
		O(logn)

	S seg.get(int p)
		It returns a[p]
		0≤p<n
		O(1)

	S seg.prod(int l, int r)
		It returns binary_operation(a[l], ..., a[r - 1]), assuming the properties of the monoid. It returns identity_element() if l=r.
		0≤l≤r≤n
		O(logn)

	S seg.all_prod()
		It returns op(a[0], ..., a[n - 1]), assuming the properties of the monoid. It returns identity_element() if n=0.
		O(1)

	(1) int seg.max_right<check_function>(int l)
	(2) int seg.max_right<F>(int l, F check_function)
		(1): It applies binary search on the segment tree. The function bool check_function(S x) should be defined.
		(2): The function object that takes S as the argument and returns bool should be defined.

		It returns an index r that satisfies both of the following :-
			r = l or check_function(binary_operation(a[l], a[l + 1], ..., a[r - 1])) = true
			r = n or check_function(binary_operation(a[l], a[l + 1], ..., a[r])) = false

		If check_function is monotone, this is the maximum r that satisfies check_function(binary_operation(a[l], a[l+1], ..,a[r-1]))=true

		if check_function is called with the same argument, it returns the same value, i.e., check_function has no side effect.
		check_function(identity_element()) = true
		0≤l≤n

		O(logn)

	(1) int seg.min_left<check_function>(int r)
	(2) int seg.min_left<F>(int r, F check_function)
		(1): It applies binary search on the segment tree. The function bool check_function(S x) should be defined.
		(2): The function object that takes S as the argument and returns bool should be defined.

		It returns an index l that satisfies both of the following :-
			l = r or check_function(binary_operation(a[l], a[l + 1], ..., a[r - 1])) = true
			l = 0 or check_function(binary_operation(a[l - 1], a[l], ..., a[r - 1])) = false

		If check_function is monotone, this is the minimum l that satisfies check_function(binary_operation(a[l], a[l+1], ..,a[r-1]))=true

		if check_function is called with the same argument, it returns the same value, i.e., check_function has no side effect.
		check_function(identity_element()) = true
		0≤r≤n

		O(logn)

	https://atcoder.github.io/ac-library/production/document_en/segtree.html

*/

void solve()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	int sum=0;
	vector<int> pre(n);
	for(int i=0;i<n;i++){
		if(s[i]=='(')sum++;
		else sum--;
		pre[i]=sum;
	}

	lazy_segtree<S,op,e,F,mapping,composition,id> tree(pre);

	while (q--)
	{
		int t,x,y;
		cin>>t>>x>>y;
		--x;
		--y;
		if(t==1){
			if(s[y]==')' && s[x]=='('){
				tree.apply(x,y,-2);
			}
			else if(s[x]==')' && s[y]=='('){
				tree.apply(x,y,2);
			}

			swap(s[x],s[y]);
		}else{
			int mn = tree.prod(x,y+1);

			int sum = tree.get(y);
			if(x>0){
				sum-=tree.get(x-1);
				mn-=tree.get(x-1);
			}

			if(sum==0 && mn==0){
				cout<<"Yes\n";
			}else{
				cout<<"No\n";
			}
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
//	parsed : 21-October-2021 12:00:27 IST