/*
	group : CodeChef - August Lunchtime 2021 Division 1
	name : Longest Spanning Substrings.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Longest_Spanning_Substrings.cpp
	url : https://www.codechef.com/LTIME99A/problems/LNGSUB
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.08.2021 21:25:50 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(string s, string t)
    {
        int sl=s.size();
        int tl=t.size();
        vector<vector<int>> koiMilGaya(sl+1,vector<int>(tl+1,0));
        int sabseLambi=0;
        for(int i=1;i<=sl;i++)
        {
            for(int j=1;j<=tl;j++)
            {
                if(s[i-1]==t[j-1])
                    koiMilGaya[i][j]=koiMilGaya[i-1][j-1]+1;
                sabseLambi=max(sabseLambi,koiMilGaya[i][j]);
            }
        }
        return sabseLambi;
    }

struct Edge {
	int u,v,w;
	bool operator<(const Edge& y) const { return w < y.w; }
};

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
	int n;
	cin>>n;

	vector<string> s(n);
	vector<Edge> edges;

	for(auto & x : s)cin>>x;

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int w=f(s[i],s[j]);
			edges.push_back({i,j,-w});
		}
	}

	sort(edges.begin(),edges.end());

	dsu d(n);
	int ans=0;
	for(auto e : edges){
		if(!d.same(e.u,e.v)){
			d.merge(e.u,e.v);
			ans+=-e.w;
		}
	}

	cout<<ans<<"\n";

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 28-August-2021 21:20:28 IST