#include<bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 2e18;

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
	return -inf;
}

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	
	map<int,int> mp;
	int pre=0;
	mp[pre]=0;
	
	for(int x : a){
		pre+=x;
		mp[pre]=0;
	}
	
	int pcnt=0;
	for(auto &pp : mp)
		pp.second=pcnt++;
	
	segtree<int,binary_operation,identity_element> tree(pcnt);
	
	vector<int> dp(n+1,-inf);
	dp[0]=0;
	pre=0;
	tree.set(mp[pre],max(tree.get(mp[pre]),dp[0]-0));
	
	for(int i=1;i<=n;i++){
		pre+=a[i-1];
		int id=mp[pre];
		dp[i]=dp[i-1];
		if(a[i-1]<0)dp[i]--;
		if(a[i-1]>0)dp[i]++;
		dp[i]=max(dp[i],i+tree.prod(0,id));
		tree.set(id,max(tree.get(id),dp[i]-i));
	}
	
	cout<<dp[n]<<"\n";
}

signed main(){
	int _t=1;
	cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}