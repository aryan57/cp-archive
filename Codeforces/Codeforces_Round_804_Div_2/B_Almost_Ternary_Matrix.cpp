/**
 *    author:  Aryan Agarwal
 *    created: 04.07.2022 21:37:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector< vector<int> > g(n,vector <int> (m));

	for(int i=0;i<n;i+=2){
		for(int j=0;j<m;j+=2){
			int k=(i/2)+(j/2);
			k%=2;
			k^=1;

			g[i][j]=k;
			g[i+1][j+1]=k;
			g[i+1][j]=k^1;
			g[i][j+1]=k^1;
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cout<<g[i][j]<<" ";
		}
		cout<<"\n";
	}
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