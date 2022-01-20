/*
	group : AtCoder - HHKB Programming Contest 2022（AtCoder Beginner Contest 235）
	name : E - MST + 1.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_MST_1.cpp
	url : https://atcoder.jp/contests/abc235/tasks/abc235_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.01.2022 18:09:47 IST
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

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

const int mxn = 2e5;
const int mxbit=19;

vector <pair <int,int> > adj[mxn+1];
int par[mxn+1][mxbit+1];
int mx[mxn+1][mxbit+1];
vector<int> tin(mxn+1),tout(mxn+1),depth(mxn+1);
int T=0;

void dfs(int u,int p,int w,int d){
	tin[u]=++T;
	par[u][0]=p;
	mx[u][0]=w;
	depth[u]=d;
	for(auto to : adj[u]){
		if(to.first!=p)dfs(to.first,u,to.second,d+1);
	}
	tout[u]=++T;
}

void preprocess(int n){
	for(int bit=1;bit<=mxbit;bit++){
		for(int i=1;i<=n;i++){
			if(par[i][bit-1]!=0){
				par[i][bit]=par[par[i][bit-1]][bit-1];
				mx[i][bit]=max(mx[i][bit-1],mx[par[i][bit-1]][bit-1]);
			}
		}
	}
}

// 0 is the dummy node
// i.e., parent of root
bool is_ancestor(int a,int b){
	if(a==0)return true;
	if(b==0)return false;
	return tin[a]<=tin[b] && tout[b]<=tout[a];
}

// lca of node 'a' and 'b' considering '1' as root
int lca(int a,int b){
	if(is_ancestor(a,b))return a;
	if(is_ancestor(b,a))return b;

	for(int bit=mxbit;bit>=0;bit--){
		if(!is_ancestor(par[a][bit],b)){
			a=par[a][bit];
		}
	}
	
	return par[a][0];
}

int cal(int u,int d){
	int ans=0;
	// dbg(u,d,ans);
	for(int bit=mxbit;bit>=0;bit--){
		if((d>>bit)&1){
			ans=max(ans,mx[u][bit]);
			u=par[u][bit];
		}
	}
	// dbg(u,d,ans);
	return ans;
}

int mxw(int a,int b){
	int l=lca(a,b);
	// dbg(a,b,l);
	return max(cal(a,-depth[l]+depth[a]),cal(b,-depth[l]+depth[b]));
}

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;
	vector<pair<int,pair <int,int> > > e(m);
	for(int i=0;i<m;i++){
		cin>>e[i].second.first>>e[i].second.second>>e[i].first;
		e[i].second.first--;
		e[i].second.second--;
	}
	sort(e.begin(),e.end());
	dsu d(n);
	for(auto v : e){
		if(!d.same(v.second.first,v.second.second)){
			d.merge(v.second.first,v.second.second);
			adj[v.second.first+1].push_back({v.second.second+1,v.first});
			adj[v.second.second+1].push_back({v.second.first+1,v.first});
		}
	}
	dfs(1,0,0,0);
	preprocess(n);
	while (q--){
		int u,v,w;
		cin>>u>>v>>w;
		cout<<(mxw(u,v)>w?"Yes\n":"No\n");
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
//	parsed : 15-January-2022 18:08:46 IST