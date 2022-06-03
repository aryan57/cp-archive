/**
 *    author:  Aryan Agarwal
 *    created: 09.05.2022 16:21:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

const int mxn = 2000;
int g[mxn][mxn];
int sum[mxn][mxn];
int n;

void solve()
{
	cin>>n;
	int tot=0;
	for(int i=0;i<n;i++){
		string s;
		cin>>s;
		for(int j=0;j<n;j++){
			g[i][j]=s[j]-'0';
			sum[i][j]=0;
			tot+=g[i][j];
		}
	}

	for(int i=0;i<n;i++){
		sum[i][n-1]=0;
		int x=i;
		int y=n-1;
		int len=n;
		while(len--){
			sum[i][n-1]+=g[x][y];
			x++;x%=n;
			y++;y%=n;
		}
	}

	for(int j=n-2;j>=0;j--){
		for(int i=0;i<=n-2;i++){
			sum[i][j]=sum[i+1][j+1];
		}
		sum[n-1][j]=0;
		int x=n-1;
		int y=j;
		int len=n;
		while(len--){
			sum[n-1][j]+=g[x][y];
			x++;x%=n;
			y++;y%=n;
		}
	}

	int mx=0;
	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)mx=max(mx,sum[i][j]);

	// cerr<<tot<<", "<<n<<", "<<mx<<"\n";

	cout<<tot+n-2*mx<<"\n";
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