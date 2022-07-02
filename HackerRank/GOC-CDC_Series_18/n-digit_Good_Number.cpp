/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 15:34:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1000;
int dp[mxn+1][9*mxn+1];
const int M = 1e9 + 7;
void solve()
{
	int n,x,y;
	cin>>n>>x>>y;

	int tot=0;

	queue<int> q;
	q.push(x);
	q.push(y);

	while (!q.empty())
	{
		int num = q.front();
		q.pop();

		tot+=dp[n][num];
		tot%=M;

		int nextl = num*10 + x;
		int nextr = num*10 + y;

		if(nextl<=9*mxn)q.push(nextl);
		if(nextr<=9*mxn)q.push(nextr);
	}

	cout<<tot;
	cout<<"\n";
	

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	dp[0][0]=1;

	for(int i=1;i<=mxn;i++){
		for(int j=0;j<=9*mxn;j++){
			for(int d=0;d<=9;d++){
				if(i==1 && d==0)continue;
				if(j-d<0)continue;

				dp[i][j] += dp[i-1][j-d];
				dp[i][j]%=M;
			}
		}
	}


	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}