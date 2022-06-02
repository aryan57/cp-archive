/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 20:23:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector< vector<int> > g(n,vector <int> (m));
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
		}
	}

	int mx=0;

	vector <int> hx  = {-1,1,-1,1};
	vector <int> hy  = {1,1,-1,-1};

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			int sum=0;
			for(int k=0;k<4;k++){
				int x=i;
				int y=j;

				while (x>=0 && x<n && y>=0 && y<m)
				{
					sum+=g[x][y];
					x+=hx[k];
					y+=hy[k];
				}
				
			}
			sum-=3*g[i][j];
			mx=max(mx,sum);
		}
	}
	cout<<mx;
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