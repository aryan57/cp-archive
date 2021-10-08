/*
	group : Codeforces - Codeforces Round #747 (Div. 2)
	name : D. The Number of Imposters.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_The_Number_of_Imposters.cpp
	url : https://codeforces.com/contest/1594/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.10.2021 21:15:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int mxn = 2e5;
vector<pair<int,int> > adj[mxn+1];
vector< vector<int> >  val(2,vector <int> (mxn+1));

bool ok[2];

int dfs(int u,int juth,int id)
{
	if(val[id][u]!=-1){
		if(!adj[u].empty() && val[id][u]!=juth){
			ok[id]=false;
		}
		return 0;
	}

	int ans=0;
	if(juth)ans++;
	val[id][u]=juth;
	for(auto to : adj[u])
	{
		if(juth){
			ans+=dfs(to.first,1-to.second,id);
		}else{
			ans+=dfs(to.first,to.second,id);
		}
	}

	return ans;
}

void solve()
{
	int n,m;
	cin>>n>>m;
	ok[0]=ok[1]=true;
	for(int i=0;i<=n;i++)
	{
		val[0][i]=val[1][i]=-1;
		adj[i].clear();
	}

	for(int i=1;i<=m;i++)
	{
		int u,v;
		cin>>u>>v;
		string s;
		cin>>s;

		if(s[0]=='i')adj[u].push_back({v,1});
		else adj[u].push_back({v,0});
	}

	int ans=0;

	for(int i=1;i<=n;i++)
	{
		if(val[0][i]!=-1){
			assert(val[1][i]!=-1);
			continue;
		}
		
		int t1=0;
		int t2=0;

		if(ok[0]){
			t1=dfs(i,0,0);
		}
		if(ok[1]){
			t2=dfs(i,1,1);
		}

		int z=0;

		if(ok[0]){
			z=max(z,t1);
		}
		if(ok[1]){
			z=max(z,t2);
		}

		ans+=z;

		if(!ok[0] && !ok[1]){
			cout<<"-1\n";
			return;
		}
	}

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
//	parsed : 08-October-2021 21:04:58 IST