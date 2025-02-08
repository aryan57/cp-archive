/**
 *    author:  Aryan Agarwal
 *    created: 08.02.2025 18:13:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long


/* 
	dsu d(int n)
	// It creates an undirected graph with n vertices and 0 edges.
	// 0<=n<=1e8
	// O(n)

	int d.merge(int a, int b)
	// It adds an edge (a, b)
	// If the vertices a and b were in the same connected component, it returns the representative of this connected component. Otherwise, it returns the representative of the new connected component.
	// 0<=a<n   0<=b<n
	// O(alpha(n)) amortized

	bool d.same(int a, int b)
	// Returns whether the vertices a and b are in the same connected component
	// 0<=a<n   0<=b<n
	// O(alpha(n)) amortized

	int d.leader(int a)
	// Returns the representative of the connected component that contains the vertex a
	// 0<=a<n
	// O(alpha(n)) amortized

	int d.size(int a)
	// Returns the size of the connected component that contains the vertex a.
	// 0<=a<n
	// O(alpha(n)) amortized

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

void solve()
{
	int n,m;
	cin>>n>>m;
	dsu d(n);
	using pii = pair<int,int>;
	vector<pii> edges(m);
	vector<bool> used(m);

	for(int i=0;i<m;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		if(!d.same(u,v)){
			d.merge(u,v);
			used[i] = true;
		}
		edges[i] = {u,v};
	}

	vector<vector<int>> groups = d.groups();
	int group_size = groups.size();
	int index=0;

	struct operation{
		int edge;
		int from;
		int to;
	};

	vector<operation> ans;

	for(int i=0;i<m;i++){
		if(ans.size()==group_size-1)break;
		if(used[i])continue;

		while (true){
			int l1 = d.leader(edges[i].first);
			int l2 = d.leader(groups[index][0]);

			if(l1==l2){
				index++;
				index%=group_size;
				continue;
			}

			operation op;
			op.edge = i+1;
			op.from = edges[i].first+1;
			op.to = l2+1;

			ans.push_back(op);
			d.merge(l1,l2);
			break;
		}
	}

	cout<<ans.size()<<"\n";
	for(auto x : ans){
		cout<<x.edge<<" "<<x.from<<" "<<x.to<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}