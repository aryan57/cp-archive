/**
 *    author:  Aryan Agarwal
 *    created: 15.05.2022 22:44:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<vector<int>> g(n,vector<int>(m));
	vector<vector<bool>> vis(n,vector<bool>(m));

	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<m;j++){
			g[i][j]=s[j]-'0';
		}
	}

	vector<int> hx = {0,1,0,-1};
	vector<int> hy = {1,0,-1,0};

	int mxx,mnx,mxy,mny;
	function<void(int,int)> dfs = [&](int x,int y){
		mxx=max(mxx,x);
		mnx=min(mnx,x);
		mxy=max(mxy,y);
		mny=min(mny,y);
		vis[x][y]=true;

		for(int k=0;k<4;k++){
			int r=x+hx[k];
			int c=y+hy[k];
			if(r>=0 && r<n && c>=0 && c<m && !vis[r][c] && g[r][c])dfs(r,c);
		}
	};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(vis[i][j] || !g[i][j])continue;

			mxx=mnx=i;
			mxy=mny=j;
			dfs(i,j);

			for(int x=mnx;x<=mxx;x++){
				for(int y=mny;y<=mxy;y++){
					if(!g[x][y]){
						cout<<"NO\n";
						return;
					}
				}
			}
		}
	}
	cout<<"YES\n";
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