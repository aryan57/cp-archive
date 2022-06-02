/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 13:40:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

const int mxn = 7e5;
vector <int> adj[mxn+1];
vector <int> col(mxn+1,-1);
int cnt[2];
int n,m;
bool dfs(int u,int parity)
{

	for(int to : adj[u])
	{
		if(col[to]==-1){
			col[to]=1^parity;
			if(to<=n)cnt[1^parity]++;
			if(!dfs(to,parity^1)) return false;
		}else if(col[to]==parity)return false;
	}
	return true;
}


void solve()
{
	
	cin>>n>>m;

	for(int i=0;i<=n+m+1;i++){
		adj[i].clear();
		col[i]=-1;
	}

	int fake=n+1;

	for(int i=1;i<=m;i++){
		int u,v;
		cin>>u>>v;
		string s;
		cin>>s;
		if(s[0]=='i'){
			adj[u].push_back(v);
			adj[v].push_back(u);
		}else{
			adj[u].push_back(fake);
			adj[fake].push_back(u);

			adj[fake].push_back(v);
			adj[v].push_back(fake);

			fake++;
		}
	}

	int ans=0;

	for(int i=1;i<=n;i++)
	{
		if(col[i]!=-1)continue;
		cnt[0]=cnt[1]=0;
		col[i]=0;
		cnt[0]=1;
		if(dfs(i,0)==false){
			cout<<"-1\n";
			return;
		}
		ans+=max(cnt[0],cnt[1]);
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
//	parsed : 15-October-2021 13:39:25 IST