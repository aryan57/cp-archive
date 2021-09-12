/*
	group : Codeforces - Codeforces Global Round 16
	name : E. Buds Re-hanging.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Buds_Re_hanging.cpp
	url : https://codeforces.com/contest/1566/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.09.2021 22:12:43 IST
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

void dfs(int u,int p, vector <int> &par,vector <set<int> > &adj)
{
	par[u]=p;
	for(int to : adj[u])
	{
		if(to==p)continue;
		dfs(to,u,par,adj);
	}
}

void solve()
{
	int n;
	cin>>n;

	vector <int> deg(n+1);
	vector <int> par(n+1);
	vector <set<int> > adj(n+1);

	for(int i=0;i<n-1;i++)
	{
		int u,v;
		cin>>u>>v;
		adj[u].insert(v);
		adj[v].insert(u);
		deg[u]++;
		deg[v]++;
	}

	dfs(1,-1,par,adj);

	vector<pair<int,int> > temp;
	set<int> b;
	for(int i=2;i<=n;i++)
	{
		bool ok = true;
		int zz=-1;
		for(int to : adj[i])
		{
			if(to==par[i])continue;
			zz=1;
			if(deg[to]!=1){
				ok=false;
				break;
			}
		}

		// dbg(i,adj[i],ok);

		if(zz==1 && ok)
		{
			b.insert(i);
		}
	}

	// dbg(b);

	while (!b.empty())
	{
		set<int> c;

		for(int z : b)
		{
			assert(z!=1);
			adj[par[z]].erase(z);
			adj[z].erase(par[z]);
			temp.push_back({1,adj[z].size()});
			deg[z]--;
			deg[par[z]]--;
			c.insert(par[z]);
			if(par[par[z]]!=-1)c.insert(par[par[z]]);
		}

		b.clear();

		for(int i : c)
		{
			if(i==1)continue;

			bool ok = true;
			int zz=-1;
			for(int to : adj[i])
			{
				if(to==par[i])continue;
				zz=1;
				if(deg[to]!=1){
					ok=false;
					break;
				}
			}

			if(zz==1 && ok)
			{
				b.insert(i);
			}
		}

	}

	// dbg(temp);
	// dbg(adj[1]);

	int d=0;
	int l=0;

	for(auto p : temp)
	{
		d+=p.first;
		l+=p.second;
	}
	int tt=adj[1].size();
	l+=max(1ll,tt);

	int ans=0;

	ans=max(ans,l-d);

	cout<<ans;
	cout<<"\n";
	
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
//	parsed : 12-September-2021 21:58:15 IST