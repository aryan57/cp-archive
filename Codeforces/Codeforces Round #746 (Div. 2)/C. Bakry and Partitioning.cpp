/*
	group : Codeforces - Codeforces Round #746 (Div. 2)
	name : C. Bakry and Partitioning.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Bakry_and_Partitioning.cpp
	url : https://codeforces.ml/contest/1592/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.10.2021 21:21:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int zl=-1;
int znl=-1;

int x=0;
bool ok = false;
int dfs(int u,int p,vector< vector<int> > &adj,vector <int> &cnt,vector <int> &a)
{
	int val=a[u];

	for(int to : adj[u]){
		if(to!=p){
			val^=dfs(to,u,adj,cnt,a);
			cnt[u]+=cnt[to];
		}
	}

	if(cnt[u]>=2){
		ok=true;
	}
	if(val==0){
		ok=true;
	}

	if(val==x && cnt[u]==0){
		cnt[u]=1;
	}


	return val;
}

void solve()
{
	int n,k;
	cin>>n>>k;

	x=0;
	vector <int> a(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
		x^=a[i];
	}
	vector< vector<int> > adj(n);
	for(int i=0;i<n-1;i++){
		int u,v;
		cin>>u>>v;
		--u;--v;
		adj[u].push_back(v);
		adj[v].push_back(u);
	}

	if(x==0){
		cout<<"YES\n";
		return;
	}

	if(k==2){
		cout<<"NO\n";
		return;
	}

	vector <int> cnt(n,0);
	ok=false;
	dfs(0,-1,adj,cnt,a);


	if(ok)
	cout<<"YES\n";
	else cout<<"NO\n";
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
//	parsed : 03-October-2021 21:18:10 IST