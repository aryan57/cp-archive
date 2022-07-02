/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 18:54:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
	int n;
	cin>>n;

	vector <string> g(n);
	for(auto &s : g)cin>>s;

	vector< vector<int> > adj(n);

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(g[i][j]=='0')continue;
			adj[i].push_back(j);
			adj[j].push_back(i);
		}
	}

	int tot=0;
	set<vector <int> > s;

	for(int i=0;i<n;i++){
		int k=adj[i].size();
		for(int t1=0;t1<k;t1++){
			for(int t2=t1+1;t2<k;t2++){
				int u = adj[i][t1];
				int v = adj[i][t2];
				if(g[u][v]=='1'){
					vector <int> temp = {i,u,v};
					sort(temp.begin(),temp.end());
					s.insert(temp);
				}
			}
		}
	}

	cout<<s.size();
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