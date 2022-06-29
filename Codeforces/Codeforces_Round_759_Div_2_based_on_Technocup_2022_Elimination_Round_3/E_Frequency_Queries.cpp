/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 12:09:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
	fenwick_tree<T> fw(int n)
	// It creates an array a_0, a_1, ..., a_{n-1} of length n
	// All the elements are initialized to 0
	// T is int, uint, ll, ull, or modint
	// 0<=n<=1e8
	// O(n)

	void fw.add(int p, T x)
	// It processes a[p] += x
	// 0<=p<n
	// O(logn)

	T fw.sum(int l, int r)
	// It returns a[l] + a[l - 1] + ... + a[r - 1]
	// 0<=l<=r<=n
	// O(logn)
*/
template <class T> struct fenwick_tree {

  public:
	fenwick_tree() : _n(0) {}
	fenwick_tree(int n) : _n(n), data(n) {}

	void add(int p, T x) {
		assert(0 <= p && p < _n);
		p++;
		while (p <= _n) {
			data[p - 1] += (x);
			p += p & -p;
		}
	}

	T sum(int l, int r) {
		assert(0 <= l && l <= r && r <= _n);
		return sum(r) - sum(l);
	}

  private:
	int _n;
	std::vector<T> data;

	T sum(int r) {
		T s = 0;
		while (r > 0) {
			s += data[r - 1];
			r -= r & -r;
		}
		return s;
	}
};

void solve()
{
	int n,q;
	cin>>n>>q;
	vector< vector<int> > adj(n);

	vector <int> a(n);
	vector <int> freq_of(n);
	vector< unordered_set <int> > freq(n+1);
	for(int i=0;i<n;i++){
		cin>>a[i];
		--a[i];
		freq[0].insert(a[i]);
	}

	fenwick_tree<int> tree(n+1);
	tree.add(0,freq[0].size());

	for(int i=2;i<=n;i++){
		int p;
		cin>>p;
		adj[i-1].push_back(p-1);
		adj[p-1].push_back(i-1);
	}

	vector< vector<vector <int> > > queries(n);
	for(int i=0;i<q;i++){
		int v,l,k;
		cin>>v>>l>>k;
		--v;
		queries[v].push_back({l,k,i});
	}

	vector <int> ans(q);

	function<void(int,int)> dfs = [&](int u,int par){
		freq_of[a[u]]++;
		freq[freq_of[a[u]]-1].erase(a[u]);
		freq[freq_of[a[u]]].insert(a[u]);


		tree.add(freq_of[a[u]]-1,-1);
		tree.add(freq_of[a[u]],1);

		

		for(const auto &v : queries[u]){
			int l = v[0];
			int k = v[1];
			int i = v[2];

			int r = n;
			int ind=-1;
			int start=l;

			while(l<=r){
				int m=(l+r)/2;
				int tot = tree.sum(start,m+1);
				if(tot>=k){
					ind=m;
					r=m-1;
				}else{
					l=m+1;
				}
			}
			if(ind==-1)ans[i]=-2;
			else {
				assert(!freq[ind].empty());
				ans[i]=*freq[ind].begin();
			}

		}


		for(int to : adj[u]){
			if(to!=par){
				dfs(to,u);
			}
		}

		freq_of[a[u]]--;
		freq[freq_of[a[u]]+1].erase(a[u]);
		freq[freq_of[a[u]]].insert(a[u]);
		
		tree.add(freq_of[a[u]]+1,-1);
		tree.add(freq_of[a[u]],1);

	};

	dfs(0,-1);

	for(int x : ans)cout<<x+1<<" ";
	cout<<"\n";
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