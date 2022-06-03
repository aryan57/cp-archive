/**
 *    author:  Aryan Agarwal
 *    created: 09.05.2022 12:51:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

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
	return a+b;
}

int identity_element()
{
	return 0;
}


void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	int ans=0;
	vector<segtree<int,binary_operation,identity_element>> v;
	for(int i=0;i<3;i++){
		v.push_back(segtree<int,binary_operation,identity_element>(2*n+1));
	}
	int sum=n;
	int parity=0;

	v[parity].set(sum,v[parity].get(sum)+1);

	for(int i=1;i<=n;i++){
		if(s[i-1]=='+'){
			sum++;
			parity++;
			parity%=3;
		}else{
			sum--;
			parity--;
			parity%=3;
			parity+=3;
			parity%=3;
		}

		ans+=v[parity].prod(sum,2*n+1);
		v[parity].set(sum,v[parity].get(sum)+1);
	}

	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}