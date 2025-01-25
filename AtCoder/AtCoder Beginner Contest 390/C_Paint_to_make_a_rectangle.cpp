/**
 *    author:  Aryan Agarwal
 *    created: 25.01.2025 17:36:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<vector<int>> g(n,vector<int>(m));
	char x;
	using pii = pair<int,int>;

	pii top = {-1,-1};
	pii bottom =  {-1,-1};


	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>x;
			if(x=='#'){
				g[i][j]=1;
				
				if(top.first==-1){
					top = bottom = {i,j};
				}
				top.first = min(top.first, i);
				top.second = min(top.second, j);

				bottom.first = max(bottom.first, i);
				bottom.second = max(bottom.second, j);
			}else if(x=='?'){
				g[i][j]=-1;
			}

		}
	}

	// dbg(top,bottom);

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			if(g[i][j]==0 && top.first<=i && i<=bottom.first && top.second<=j && j<=bottom.second){
				cout<<"No\n";
				return;
			}

		}
	}
	cout<<"Yes\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}