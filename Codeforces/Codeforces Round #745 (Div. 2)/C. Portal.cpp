/*
	group : Codeforces - Codeforces Round #745 (Div. 2)
	name : C. Portal.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Portal.cpp
	url : https://codeforces.com/contest/1581/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.09.2021 16:14:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 2e18;

void solve()
{
	int n,m;
	cin>>n>>m;

	vector< vector<int> > g(n+1,vector <int> (m+1));
	vector< vector<int> > gr(n+1,vector <int> (m+1));

	vector< vector<int> > c(m+1,vector <int> (n+1));
	vector< vector<int> > r(n+1,vector <int> (m+1));

	for(int i=1;i<=n;i++){
		string s;
		cin>>s;

		for(int j=1;j<=m;j++){
			g[i][j]=s[j-1]-'0';
			r[i][j]=r[i][j-1]+g[i][j];
			gr[i][j]=-gr[i-1][j-1]+gr[i-1][j]+gr[i][j-1]+g[i][j];
		}
	}

	for(int j=1;j<=m;j++){

		for(int i=1;i<=n;i++){
			c[j][i]=c[j][i-1]+g[i][j];
		}
	}

	int ans=n*m;

	for(int b=4;b<=m;b++)
	{
		vector< vector<int> > xx(n+1,vector <int> (m+1,INF));
		for(int i=2;i<=n;i++)
		{

			for(int j=1;j<=m && j+b-1<=m;j++)
			{
				xx[i][j] = 0;
				xx[i][j] += b-2 - (r[i][j+b-2]-r[i][j]) ;
				xx[i][j] += i-1- c[j+b-1][i-1];
				xx[i][j] += i-1-c[j][i-1];
				xx[i][j] += gr[i-1][j+b-2]-gr[i-1][j];
				
			}
		}

		vector <int> mn(m+1,INF);

		for(int i=n-4;i>=1;i--)
		{

			for(int j=1;j<=m && j+b-1<=m;j++)
			{
				mn[j]=min(mn[j],xx[i+4][j]);
				
			}

			for(int j=1;j<=m && j+b-1<=m;j++)
			{
				int ss=0;

				ss-= i- c[j][i];
				ss-= i- c[j+b-1][i];
				ss-= gr[i][j+b-2]-gr[i][j];

				ss+= b-2 - (r[i][j+b-2]-r[i][j]);

				ss+= mn[j];

				assert(ss>=0);

				ans=min(ans,ss);
				
			}
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
//	parsed : 30-September-2021 16:02:30 IST