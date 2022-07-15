/**
 *    author:  Aryan Agarwal
 *    created: 14.07.2022 22:02:12 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxbit = 18;

void solve()
{
	int n;
	cin>>n;
	vector <vector<int>> adj(n+1);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}
	int h[n+1]={};
	int p[n+1][mxbit]={};
	int T=0;
	int tin[n+1]={};
	int tout[n+1]={};
	function <void(int,int,int)> dfs = [&](int u,int par,int hh){
		p[u][0]=par;
		h[u]=hh;
		tin[u]=++T;
		for(int to : adj[u]){
			if(to!=par)dfs(to,u,hh+1);
		}
		tout[u]=++T;
	};
	dfs(1,0,0);

	for(int bit=1;bit<mxbit;bit++){
		for(int i=1;i<=n;i++){
			p[i][bit]=p[p[i][bit-1]][bit-1];
		}
	}

	function<bool(int,int)> is_ancestor = [&](int u,int v)->bool{
		if(u==0)return true;
		if(v==0)return false;

		return (tin[u]<=tin[v] && tout[v]<=tout[u]);
	};

	function<int(int,int)> lca = [&](int x,int y)->int{
		if(is_ancestor(x,y))return x;
		if(is_ancestor(y,x))return y;

		for(int bit=mxbit-1;bit>=0;bit--){
			if(!is_ancestor(p[x][bit],y)){
				x=p[x][bit];
			}
		}
		return p[x][0];
	};

	int q;
	cin>>q;
	while (q--)
	{
		int k;
		cin>>k;

		vector <int> node(k);
		for(int &x : node){
			cin>>x;
		}

		sort(node.begin(),node.end(),[&h](const int &i,const int &j)->bool{
			return h[i]<h[j];
		});

		if(k<=2){
			cout<<"YES\n";
			continue;
		}
		bool ok = true;

		vector <int> used(k);

		int last=-1;
		int head1=-1;
		for(int i=k-1;i>=0;i--){
			if(lca(node[i],node[k-1])!=node[i]){
				if(last==-1)last=i;
			}else{
				used[i]=1;
				head1=node[i];
			}
		}

		if(last==-1){
			cout<<"YES\n";
			continue;
		}
		int head2=-1;
		for(int i=k-1;i>=0;i--){
			if(used[i])continue;
			if(lca(node[i],node[last])==node[i])
				used[i]=2;
				head2=node[i];
		}

		for(const auto &b : used){
			if(b==0){
				ok=false;
				break;
			}
		}

		int mainLca = lca(head1,head2);

		for(int i=0;i<k;i++){
			if(used[i]==1 && lca(node[i],head2)!=mainLca)ok=false;
			if(used[i]==2 && lca(node[i],head1)!=mainLca)ok=false;
		}

		cout<<(ok?"YES\n":"NO\n");
	}
	
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