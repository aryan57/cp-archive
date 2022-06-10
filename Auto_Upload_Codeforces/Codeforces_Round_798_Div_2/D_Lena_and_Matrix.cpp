/**
 *    author:  Aryan Agarwal
 *    created: 10.06.2022 23:44:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector <string> g(n+2);
	for(int i=1;i<=n;i++){
		cin>>g[i];
		g[i]="#"+g[i];
	}
	const int inf = 2e18;
	vector< vector<int> > sx(n+2,vector <int> (m+2,-inf));
	vector< vector<int> > sn(n+2,vector <int> (m+2,inf));

	for(int i=1;i<=n;i++){
		for(int j=m;j>=1;j--){
			sn[i][j]=min(sn[i][j],sn[i-1][j]);
			sn[i][j]=min(sn[i][j],sn[i][j+1]);
			if(g[i][j]=='B')sn[i][j]=min(sn[i][j],i-j);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=1;j<=m;j++){
			sx[i][j]=max(sx[i][j],sx[i+1][j]);
			sx[i][j]=max(sx[i][j],sx[i][j-1]);
			if(g[i][j]=='B')sx[i][j]=max(sx[i][j],i-j);
		}
	}
	vector< vector<int> > px(n+2,vector <int> (m+2,-inf));
	vector< vector<int> > pn(n+2,vector <int> (m+2,inf));

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			pn[i][j]=min(pn[i][j],pn[i-1][j]);
			pn[i][j]=min(pn[i][j],pn[i][j-1]);
			if(g[i][j]=='B')pn[i][j]=min(pn[i][j],i+j);
		}
	}
	for(int i=n;i>=1;i--){
		for(int j=m;j>=1;j--){
			px[i][j]=max(px[i][j],px[i+1][j]);
			px[i][j]=max(px[i][j],px[i][j+1]);
			if(g[i][j]=='B')px[i][j]=max(px[i][j],i+j);
		}
	}

	pair <int,int> ans = {-1,-1};
	int l=0,r=inf;
	while (l<=r)
	{
		int t = (l+r)/2;
		bool ok = false;

		for(int i=1;i<=n;i++){
			for(int j=1;j<=m;j++){
				if(i+j-t > pn[i][j])continue;
				if(i+j+t < px[i][j])continue;

				if(i-j-t > sn[i][j])continue;
				if(i-j+t < sx[i][j])continue;

				ok=true;
				ans={i,j};
				break;
			}
			if(ok)break;
		}

		if(ok){
			r=t-1;
		}else{
			l=t+1;
		}
	}
	cout<<ans.first<<" "<<ans.second<<"\n";
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