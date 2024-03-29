/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 18:56:30 IST
**/

/***********
WRITE THIS AT THE TOPMOST OF YOUR CODE
***********/
#include <utility>
#include <cassert>
#include <numeric>
#include <type_traits>

namespace atcoder {

namespace internal {

// @param m `1 <= m`
// @return x mod m
constexpr long long safe_mod(long long x, long long m) {
	x %= m;
	if (x < 0) x += m;
	return x;
}

// Fast modular multiplication by barrett reduction
// Reference: https://en.wikipedia.org/wiki/Barrett_reduction
// NOTE: reconsider after Ice Lake
struct barrett {
	unsigned int _m;
	unsigned long long im;

	// @param m `1 <= m < 2^31`
	barrett(unsigned int m) : _m(m), im((unsigned long long)(-1) / m + 1) {}

	// @return m
	unsigned int umod() const { return _m; }

	// @param a `0 <= a < m`
	// @param b `0 <= b < m`
	// @return `a * b % m`
	unsigned int mul(unsigned int a, unsigned int b) const {
		// [1] m = 1
		// a = b = im = 0, so okay

		// [2] m >= 2
		// im = ceil(2^64 / m)
		// -> im * m = 2^64 + r (0 <= r < m)
		// let z = a*b = c*m + d (0 <= c, d < m)
		// a*b * im = (c*m + d) * im = c*(im*m) + d*im = c*2^64 + c*r + d*im
		// c*r + d*im < m * m + m * im < m * m + 2^64 + m <= 2^64 + m * (m + 1) < 2^64 * 2
		// ((ab * im) >> 64) == c or c + 1
		unsigned long long z = a;
		z *= b;

		unsigned long long x =
			(unsigned long long)(((unsigned __int128)(z)*im) >> 64);

		unsigned int v = (unsigned int)(z - x * _m);
		if (_m <= v) v += _m;
		return v;
	}
};

// @param n `0 <= n`
// @param m `1 <= m`
// @return `(x ** n) % m`
constexpr long long pow_mod_constexpr(long long x, long long n, int m) {
	if (m == 1) return 0;
	unsigned int _m = (unsigned int)(m);
	unsigned long long r = 1;
	unsigned long long y = safe_mod(x, m);
	while (n) {
		if (n & 1) r = (r * y) % _m;
		y = (y * y) % _m;
		n >>= 1;
	}
	return r;
}

// Reference:
// M. Forisek and J. Jancina,
// Fast Primality Testing for Integers That Fit into a Machine Word
// @param n `0 <= n`
constexpr bool is_prime_constexpr(int n) {
	if (n <= 1) return false;
	if (n == 2 || n == 7 || n == 61) return true;
	if (n % 2 == 0) return false;
	long long d = n - 1;
	while (d % 2 == 0) d /= 2;
	constexpr long long bases[3] = {2, 7, 61};
	for (long long a : bases) {
		long long t = d;
		long long y = pow_mod_constexpr(a, t, n);
		while (t != n - 1 && y != 1 && y != n - 1) {
			y = y * y % n;
			t <<= 1;
		}
		if (y != n - 1 && t % 2 == 0) {
			return false;
		}
	}
	return true;
}
template <int n> constexpr bool is_prime = is_prime_constexpr(n);

// @param b `1 <= b`
// @return pair(g, x) s.t. g = gcd(a, b), xa = g (mod b), 0 <= x < b/g
constexpr std::pair<long long, long long> inv_gcd(long long a, long long b) {
	a = safe_mod(a, b);
	if (a == 0) return {b, 0};

	// Contracts:
	// [1] s - m0 * a = 0 (mod b)
	// [2] t - m1 * a = 0 (mod b)
	// [3] s * |m1| + t * |m0| <= b
	long long s = b, t = a;
	long long m0 = 0, m1 = 1;

	while (t) {
		long long u = s / t;
		s -= t * u;
		m0 -= m1 * u;  // |m1 * u| <= |m1| * s <= b

		// [3]:
		// (s - t * u) * |m1| + t * |m0 - m1 * u|
		// <= s * |m1| - t * u * |m1| + t * (|m0| + |m1| * u)
		// = s * |m1| + t * |m0| <= b

		auto tmp = s;
		s = t;
		t = tmp;
		tmp = m0;
		m0 = m1;
		m1 = tmp;
	}
	// by [3]: |m0| <= b/g
	// by g != b: |m0| < b/g
	if (m0 < 0) m0 += b / s;
	return {s, m0};
}

// Compile time primitive root
// @param m must be prime
// @return primitive root (and minimum in now)
constexpr int primitive_root_constexpr(int m) {
	if (m == 2) return 1;
	if (m == 167772161) return 3;
	if (m == 469762049) return 3;
	if (m == 754974721) return 11;
	if (m == 998244353) return 3;
	int divs[20] = {};
	divs[0] = 2;
	int cnt = 1;
	int x = (m - 1) / 2;
	while (x % 2 == 0) x /= 2;
	for (int i = 3; (long long)(i)*i <= x; i += 2) {
		if (x % i == 0) {
			divs[cnt++] = i;
			while (x % i == 0) {
				x /= i;
			}
		}
	}
	if (x > 1) {
		divs[cnt++] = x;
	}
	for (int g = 2;; g++) {
		bool ok = true;
		for (int i = 0; i < cnt; i++) {
			if (pow_mod_constexpr(g, (m - 1) / divs[i], m) == 1) {
				ok = false;
				break;
			}
		}
		if (ok) return g;
	}
}
template <int m> constexpr int primitive_root = primitive_root_constexpr(m);

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

namespace internal {

template <class T>
using is_signed_int128 =
	typename std::conditional<std::is_same<T, __int128_t>::value ||
								  std::is_same<T, __int128>::value,
							  std::true_type,
							  std::false_type>::type;

template <class T>
using is_unsigned_int128 =
	typename std::conditional<std::is_same<T, __uint128_t>::value ||
								  std::is_same<T, unsigned __int128>::value,
							  std::true_type,
							  std::false_type>::type;

template <class T>
using make_unsigned_int128 =
	typename std::conditional<std::is_same<T, __int128_t>::value,
							  __uint128_t,
							  unsigned __int128>;

template <class T>
using is_integral = typename std::conditional<std::is_integral<T>::value ||
												  is_signed_int128<T>::value ||
												  is_unsigned_int128<T>::value,
											  std::true_type,
											  std::false_type>::type;

template <class T>
using is_signed_int = typename std::conditional<(is_integral<T>::value &&
												 std::is_signed<T>::value) ||
													is_signed_int128<T>::value,
												std::true_type,
												std::false_type>::type;

template <class T>
using is_unsigned_int =
	typename std::conditional<(is_integral<T>::value &&
							   std::is_unsigned<T>::value) ||
								  is_unsigned_int128<T>::value,
							  std::true_type,
							  std::false_type>::type;

template <class T>
using to_unsigned = typename std::conditional<
	is_signed_int128<T>::value,
	make_unsigned_int128<T>,
	typename std::conditional<std::is_signed<T>::value,
							  std::make_unsigned<T>,
							  std::common_type<T>>::type>::type;


template <class T>
using is_signed_int_t = std::enable_if_t<is_signed_int<T>::value>;

template <class T>
using is_unsigned_int_t = std::enable_if_t<is_unsigned_int<T>::value>;

template <class T> using to_unsigned_t = typename to_unsigned<T>::type;

}  // namespace internal

}  // namespace atcoder

namespace atcoder {

namespace internal {

struct modint_base {};
struct static_modint_base : modint_base {};

template <class T> using is_modint = std::is_base_of<modint_base, T>;
template <class T> using is_modint_t = std::enable_if_t<is_modint<T>::value>;

}  // namespace internal

template <int m, std::enable_if_t<(1 <= m)>* = nullptr>
struct static_modint : internal::static_modint_base {
	using mint = static_modint;

  public:
	static constexpr int mod() { return m; }
	static mint raw(int v) {
		mint x;
		x._v = v;
		return x;
	}

	static_modint() : _v(0) {}
	template <class T, internal::is_signed_int_t<T>* = nullptr>
	static_modint(T v) {
		long long x = (long long)(v % (long long)(umod()));
		if (x < 0) x += umod();
		_v = (unsigned int)(x);
	}
	template <class T, internal::is_unsigned_int_t<T>* = nullptr>
	static_modint(T v) {
		_v = (unsigned int)(v % umod());
	}
	static_modint(bool v) { _v = ((unsigned int)(v) % umod()); }

	unsigned int val() const { return _v; }

	mint& operator++() {
		_v++;
		if (_v == umod()) _v = 0;
		return *this;
	}
	mint& operator--() {
		if (_v == 0) _v = umod();
		_v--;
		return *this;
	}
	mint operator++(int) {
		mint result = *this;
		++*this;
		return result;
	}
	mint operator--(int) {
		mint result = *this;
		--*this;
		return result;
	}

	mint& operator+=(const mint& rhs) {
		_v += rhs._v;
		if (_v >= umod()) _v -= umod();
		return *this;
	}
	mint& operator-=(const mint& rhs) {
		_v -= rhs._v;
		if (_v >= umod()) _v += umod();
		return *this;
	}
	mint& operator*=(const mint& rhs) {
		unsigned long long z = _v;
		z *= rhs._v;
		_v = (unsigned int)(z % umod());
		return *this;
	}
	mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

	mint operator+() const { return *this; }
	mint operator-() const { return mint() - *this; }

	mint pow(long long n) const {
		assert(0 <= n);
		mint x = *this, r = 1;
		while (n) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	mint inv() const {
		if (prime) {
			assert(_v);
			return pow(umod() - 2);
		} else {
			auto eg = internal::inv_gcd(_v, m);
			assert(eg.first == 1);
			return eg.second;
		}
	}

	friend mint operator+(const mint& lhs, const mint& rhs) {
		return mint(lhs) += rhs;
	}
	friend mint operator-(const mint& lhs, const mint& rhs) {
		return mint(lhs) -= rhs;
	}
	friend mint operator*(const mint& lhs, const mint& rhs) {
		return mint(lhs) *= rhs;
	}
	friend mint operator/(const mint& lhs, const mint& rhs) {
		return mint(lhs) /= rhs;
	}
	friend bool operator==(const mint& lhs, const mint& rhs) {
		return lhs._v == rhs._v;
	}
	friend bool operator!=(const mint& lhs, const mint& rhs) {
		return lhs._v != rhs._v;
	}

  private:
	unsigned int _v;
	static constexpr unsigned int umod() { return m; }
	static constexpr bool prime = internal::is_prime<m>;
};

template <int id> struct dynamic_modint : internal::modint_base {
	using mint = dynamic_modint;

  public:
	static int mod() { return (int)(bt.umod()); }
	static void set_mod(int m) {
		assert(1 <= m);
		bt = internal::barrett(m);
	}
	static mint raw(int v) {
		mint x;
		x._v = v;
		return x;
	}

	dynamic_modint() : _v(0) {}
	template <class T, internal::is_signed_int_t<T>* = nullptr>
	dynamic_modint(T v) {
		long long x = (long long)(v % (long long)(mod()));
		if (x < 0) x += mod();
		_v = (unsigned int)(x);
	}
	template <class T, internal::is_unsigned_int_t<T>* = nullptr>
	dynamic_modint(T v) {
		_v = (unsigned int)(v % mod());
	}
	dynamic_modint(bool v) { _v = ((unsigned int)(v) % mod()); }

	unsigned int val() const { return _v; }

	mint& operator++() {
		_v++;
		if (_v == umod()) _v = 0;
		return *this;
	}
	mint& operator--() {
		if (_v == 0) _v = umod();
		_v--;
		return *this;
	}
	mint operator++(int) {
		mint result = *this;
		++*this;
		return result;
	}
	mint operator--(int) {
		mint result = *this;
		--*this;
		return result;
	}

	mint& operator+=(const mint& rhs) {
		_v += rhs._v;
		if (_v >= umod()) _v -= umod();
		return *this;
	}
	mint& operator-=(const mint& rhs) {
		_v += mod() - rhs._v;
		if (_v >= umod()) _v -= umod();
		return *this;
	}
	mint& operator*=(const mint& rhs) {
		_v = bt.mul(_v, rhs._v);
		return *this;
	}
	mint& operator/=(const mint& rhs) { return *this = *this * rhs.inv(); }

	mint operator+() const { return *this; }
	mint operator-() const { return mint() - *this; }

	mint pow(long long n) const {
		assert(0 <= n);
		mint x = *this, r = 1;
		while (n) {
			if (n & 1) r *= x;
			x *= x;
			n >>= 1;
		}
		return r;
	}
	mint inv() const {
		auto eg = internal::inv_gcd(_v, mod());
		assert(eg.first == 1);
		return eg.second;
	}

	friend mint operator+(const mint& lhs, const mint& rhs) {
		return mint(lhs) += rhs;
	}
	friend mint operator-(const mint& lhs, const mint& rhs) {
		return mint(lhs) -= rhs;
	}
	friend mint operator*(const mint& lhs, const mint& rhs) {
		return mint(lhs) *= rhs;
	}
	friend mint operator/(const mint& lhs, const mint& rhs) {
		return mint(lhs) /= rhs;
	}
	friend bool operator==(const mint& lhs, const mint& rhs) {
		return lhs._v == rhs._v;
	}
	friend bool operator!=(const mint& lhs, const mint& rhs) {
		return lhs._v != rhs._v;
	}

  private:
	unsigned int _v;
	static internal::barrett bt;
	static unsigned int umod() { return bt.umod(); }
};
template <int id> internal::barrett dynamic_modint<id>::bt = 998244353;

using modint998244353 = static_modint<998244353>;
using modint1000000007 = static_modint<1000000007>;
using modint = dynamic_modint<-1>;

namespace internal {

template <class T>
using is_static_modint = std::is_base_of<internal::static_modint_base, T>;

template <class T>
using is_static_modint_t = std::enable_if_t<is_static_modint<T>::value>;

template <class> struct is_dynamic_modint : public std::false_type {};
template <int id>
struct is_dynamic_modint<dynamic_modint<id>> : public std::true_type {};

template <class T>
using is_dynamic_modint_t = std::enable_if_t<is_dynamic_modint<T>::value>;

}  // namespace internal

}  // namespace atcoder

/*
	Constructor
	// (1) modint x()
	// It is the default constructor of modint. 0 will be stored.
	// (2) modint x<T>(T y)
	// It is the constructor for the integer type T(int, char, ull, bool, ...). y is stored in modint after taking mod.

	set_mod
	// void modint::set_mod(int m)
	// It sets the mod. It must be called first.
	// 1 <= m <= 2e9+1000
	// O(1)

	mod
	// int modint::mod()
	// It returns the mod.

	val
	// int x.val();
	// It returns the value that is stored in x.

	pow
	// modint x.pow(ll n)
	// It returns x^(n)
	// 0<=n
	// O(logn)

	inv
	// modint x.inv()
	// It returns y with xy ≡ 1
	// gcd(x.val(), mod) = 1
	// O(logmod)

	raw
	// modint modint::raw(int x)
	// It returns modint(x) without taking mod
	// When the value more than or equal to mod is assigned to modint::raw(x), the behavior is undefined.
	// 0<=x<mod

*/
using namespace atcoder;
// using mint = modint;   // write  mint::set_mod(SOME_NUMBER); in the solve() function
using mint = modint998244353;
// using mint = modint1000000007;

#include <bits/stdc++.h>
using namespace std;

#define int long long


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

mint binary_operation(mint a,mint b)
{
	return a+b;
}

mint identity_element()
{
	return 0;
}

void solve()
{
	int n,q;
	cin>>n>>q;
	vector <mint> a(n+1);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		a[i]=x;
	}
	segtree<mint,binary_operation,identity_element> tree1(a);
	for(int i=1;i<=n;i++){
		a[i]*=i;
	}
	segtree<mint,binary_operation,identity_element> tree2(a);
	for(int i=1;i<=n;i++){
		a[i]*=i;
	}
	segtree<mint,binary_operation,identity_element> tree3(a);

	while (q--)
	{
		int op;
		cin>>op;
		if(op==1){
			int x,v;
			cin>>x>>v;
			mint z=v;
			tree1.set(x,z);
			z*=x;
			tree2.set(x,z);
			z*=x;
			tree3.set(x,z);
		}else{
			int x;
			cin>>x;

			mint ans=0;

			mint t1=(x+1);
			t1*=(x+2);
			t1*=tree1.prod(1,x+1);
			t1/=2;

			mint t2=2*x+3;
			t2*=tree2.prod(1,x+1);
			t2/=2;

			mint t3 = tree3.prod(1,x+1);
			t3/=2;

			ans=t1-t2+t3;

			cout<<ans.val();
			cout<<"\n";
		}
	}
	

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}