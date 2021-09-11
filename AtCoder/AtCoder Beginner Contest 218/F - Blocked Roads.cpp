/*
	group : AtCoder - AtCoder Beginner Contest 218
	name : F - Blocked Roads.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Blocked_Roads.cpp
	url : https://atcoder.jp/contests/abc218/tasks/abc218_f
*/
/**
 *    author:  Aryan Agarwal
 *    created: 11.09.2021 18:41:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n,m;

const int INF = 2e18;
vector <int> adj[401];

int f(pair <int,int>  p)
{
	queue<int> q;
	vector<bool> v(n);
	vector<int> d(n,INF) ;
		
	q.push(0);
	v[0] = true;
	d[0]=0;
	
	while (!q.empty()) {
	
		int parent_node = q.front();
		q.pop();
	
		for (int child_node : adj[parent_node]) {

			if(parent_node==p.first && child_node==p.second)continue;

			if (!v[child_node])
			{
				v[child_node] = true;
				q.push(child_node);
				d[child_node] = d[parent_node] + 1;
			}
		}
	}

	return d[n-1];
}

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
	cin>>n>>m;

	
	vector< pair <int,int>  > e(m);
	for(int i=0;i<m;i++)
	{
		int u,v;
		cin>>u>>v;
		--u;--v;
		e[i]={u,v};
		adj[u].push_back(v);
	}

	queue<int> q;
	vector<bool> visited(n);
	vector<int> distance(n,INF), parent(n);
	
	q.push(0);
	visited[0] = true;
	parent[0] = -1;
	distance[0]=0;
	
	while (!q.empty()) {
	
		int parent_node = q.front();
		q.pop();
	
		for (int child_node : adj[parent_node]) {
	
			if (!visited[child_node])
			{
				visited[child_node] = true;
				q.push(child_node);
				distance[child_node] = distance[parent_node] + 1;
				parent[child_node] = parent_node;
			}
		}
	}

	map<pair <int,int> ,bool > mp;
	int cur=n-1;
	while(cur!=-1)
	{
		mp[{parent[cur],cur}]=true;
		cur=parent[cur];
	}

	// dbg(mp);

	for(int i=0;i<m;i++)
	{
		if(distance[n-1]==INF){
			cout<<"-1\n";
			continue;
		}
		if(!mp[e[i]]){
			cout<<distance[n-1];
			cout<<"\n";
			continue;
		}

		// dbg(i,e[i]);

		int z=f(e[i]);
		if(z==INF){
			cout<<"-1\n";
			continue;
		}
		cout<<z;
		cout<<"\n";

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
//	parsed : 11-September-2021 18:41:50 IST