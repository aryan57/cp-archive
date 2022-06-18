/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 20:09:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	int ans=n*m;
	vector< vector<int> > g(n,vector <int> (m));
	int maxx=2e10;
	maxx=-maxx;
	int x=-1;
	int y=-1;
	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			
			if(maxx<g[i][j]){
				maxx=g[i][j];
				x=i+1;
				y=j+1;
			}
		}
	}

	for(int h=1;h<=n;h++){
		for(int w=1;w<=m;w++){
			bool ok = true;

			for(int a=1;a<=n-h+1;a++){
				for(int b=1;b<=m-w+1;b++){
					if(a<=x && x<=a+h-1 && b<=y && y<=b+w-1)continue;
					ok=false;
				}
			}

			if(ok)ans=min(ans,h*w);
		}
	}
	cout<<ans;
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