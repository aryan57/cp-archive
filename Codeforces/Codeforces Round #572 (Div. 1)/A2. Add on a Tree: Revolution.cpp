/*
	group : Codeforces - Codeforces Round #572 (Div. 1)
	name : A2. Add on a Tree: Revolution.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A2_Add_on_a_Tree_Revolution.cpp
	url : https://codeforces.com/problemset/problem/1188/A2
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 15:18:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn=1000;


struct Edge{
	int u,v,w;
};


vector<bool> is_leaf(mxn);
vector<int> leaf(mxn);
vector<pair<int,int>> adj[mxn];
vector<Edge> edge(mxn);
vector<Edge> ans;

set<int> leaves;

bool ok = true;
int dfs(int u,int p){

	bool l=true;
	leaf[u]=u;
	for(auto to : adj[u]){
		if(to.first==p)continue;
		l=false;
		leaf[u]=dfs(to.first,u);
	}

	if(l){
		if(leaves.size()<3){
			leaves.insert(u);
		}
		is_leaf[u]=true;
		
		return u;
	}else if(adj[u].size()==2){
		ok=false;
		return 0;
	}

	return leaf[u];
}

void add(Edge edge,int W){

	assert(is_leaf[edge.u]^is_leaf[edge.v]);

	int l1,l2,t;
	l1=l2=t=-1;

	if(is_leaf[edge.u]){

		l1=edge.u;
		for(auto to : adj[edge.v]){
			if(!is_leaf[to.first] || to.first==l1)continue;
			l2=to.first;
			break;
		}
	}else{

		l1=edge.v;
		for(auto to : adj[edge.u]){
			if(!is_leaf[to.first] || to.first==l1)continue;
			l2=to.first;
			break;
		}
	}

	for(int z : leaves){
		// cerr<<z<<" ";
		if(z!=l1 && z!=l2){
			t=z;
			break;
		}
	}

	assert(l1!=-1 && l2!=-1);
	assert(t!=-1);

	Edge e;
	e={l1,l2,edge.w/2};
	ans.push_back(e);
	e={l1,t,edge.w/2};
	ans.push_back(e);
	e={l2,t,-edge.w/2};
	ans.push_back(e);

}

void solve()
{
	int n;
	cin>>n;
	vector<int> deg(n);
	for(int i=0;i<n-1;i++){
		int u,v,w;
		cin>>u>>v>>w;
		--u;--v;
		deg[u]++;
		deg[v]++;
		adj[u].push_back({v,w});
		adj[v].push_back({u,w});
		edge[i]={u,v,w};
	}
	if(n==2){
		cout<<"YES\n1\n";
		cout<<edge[0].u+1<<" "<<edge[0].v+1<<" "<<edge[0].w<<"\n";
		return;
	}
	
	int root=0;
	for(int i=0;i<n;i++){
		if(deg[i]>1){
			root=i;
			break;
		}
	}

	dfs(root,-1);

	// for(int x : leaves){
	// 	cerr<<x<<" ";
	// }cerr<<"\n";

	if(!ok){
		cout<<"NO\n";
		return;
	}



	for(int i=0;i<n-1;i++){

		if(is_leaf[edge[i].u] || is_leaf[edge[i].v]){
			add(edge[i],edge[i].w);
			continue;
		}
		
		int u1,u2,v1,v2;
		u1=u2=v1=v2=-1;

		for(auto to : adj[edge[i].u]){
			if(to.first==edge[i].v)continue;
			if(u1==-1){
				u1=to.first;
			}else if(u2==-1){
				u2=to.first;
			}else{
				break;
			}
		}

		for(auto to : adj[edge[i].v]){
			if(to.first==edge[i].u)continue;
			if(v1==-1){
				v1=to.first;
			}else if(v2==-1){
				v2=to.first;
			}else{
				break;
			}
		}

		// cerr<<u1<<" "<<u2<<" "<<v1<<" "<<v2<<"\n";
		// cerr<<leaf[u1]<<" "<<leaf[u2]<<" "<<leaf[v1]<<" "<<leaf[v2]<<"\n";

		assert(u1!=-1 && u2!=-1);
		assert(v1!=-1 && v2!=-1);

		Edge e;
		e={leaf[u1],leaf[v1],edge[i].w/2};
		ans.push_back(e);
		e={leaf[u2],leaf[v2],edge[i].w/2};
		ans.push_back(e);

		e={leaf[u1],leaf[u2],-edge[i].w/2};
		ans.push_back(e);
		e={leaf[v1],leaf[v2],-edge[i].w/2};
		ans.push_back(e);

	}

	cout<<"YES\n";
	cout<<ans.size()<<"\n";
	for(auto z : ans){
		cout<<z.u+1<<" "<<z.v+1<<" "<<z.w<<"\n";
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
//	parsed : 15-August-2021 14:56:44 IST
//	parsed : 15-August-2021 15:37:09 IST