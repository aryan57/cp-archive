/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 21:04:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

int g[1000][1000];
pair <int,int> dp[1000][1000];
int n,m;
const int inf = 1e9;

pair <int,int> f(int x,int y){
	if(dp[x][y].first!=-1)return dp[x][y];
	pair <int,int> ans = {inf,-inf};
	pair <int,int> dow , rig;
	if(x+1<n){
		dow = f(x+1,y);
		dow.first+=g[x][y];
		dow.second+=g[x][y];
		ans.first = min(ans.first,dow.first);
		ans.second = max(ans.second,dow.second);
	}
	if(y+1<m){
		rig = f(x,y+1);
		rig.first+=g[x][y];
		rig.second+=g[x][y];
		ans.first = min(ans.first,rig.first);
		ans.second = max(ans.second,rig.second);
	}

	if(ans.first==inf)ans={g[x][y],g[x][y]};

	return dp[x][y]=ans;
}

void solve()
{
	cin>>n>>m;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			dp[i][j]={-1,-1};
			if(g[i][j]==-1)g[i][j]=0;
		}
	}
	int steps=n+m-1;
	if(steps%2){
		cout<<"NO\n";
		return;
	}
	steps/=2;
	pair <int,int> x = f(0,0);
	if(x.first<=steps && steps<=x.second)cout<<"YES\n";
	else cout<<"NO\n";
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