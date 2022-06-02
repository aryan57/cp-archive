/**
 *    author:  Aryan Agarwal
 *    created: 07.05.2022 09:25:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1ll<<17;

vector <pair <int,int> > adj[mxn+1];
vector <int> nodeval(mxn+1);
vector <int> edgeval(mxn);
int p;

void dfs(int u,int par,int &touse){

	int isset = (nodeval[u]>>p)&1;

	for(auto [v,e] : adj[u]){
		if(v!=par){
			if(isset){
				edgeval[e] = (1ll<<p) + touse;
				nodeval[v] = touse;
			}else{
				edgeval[e] = touse;
				nodeval[v] = (1ll<<p) + touse;
			}
			touse++;
			dfs(v,u,touse);
		}
	}
}

void solve()
{
	
	cin>>p;
	int n=(1ll<<p);

	for(int i=1;i<=n;i++)adj[i].clear();

	for(int i=1;i<n;i++){
		int u,v;
		cin>>u>>v;
		adj[u].push_back({v,i});
		adj[v].push_back({u,i});
	}

	nodeval[1]=n;
	int touse=1;
	dfs(1,1,touse);
	cout<<1<<"\n";
	for(int i=1;i<=n;i++)cout<<nodeval[i]<<" ";
	cout<<"\n";
	for(int i=1;i<=n-1;i++)cout<<edgeval[i]<<" ";
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