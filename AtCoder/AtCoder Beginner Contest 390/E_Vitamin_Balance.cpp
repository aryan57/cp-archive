/**
 *    author:  Aryan Agarwal
 *    created: 25.01.2025 18:23:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

using pii = pair<int,int>;

vector<int> fun(const vector<pii> &v, const int x){
	int n = v.size();

	vector<vector<int>> dp(n,vector<int> (x+1));

	for(int i=1;i<n;i++){
		for(int j=1;j<=x;j++){
			dp[i][j] = max(dp[i][j], dp[i][j-1]);

			dp[i][j] = max(dp[i][j], dp[i-1][j]);
			if(j>=v[i].second)
			dp[i][j] = max(dp[i][j], dp[i-1][j-v[i].second] + v[i].first);
		}
	}

	return dp[n-1];
}

void solve()
{
	int n,x;
	cin>>n>>x;
	vector<vector<pii>> v(3);

	for(int i=0;i<3;i++){
		v[i].push_back({0,0});
	}

	for(int i=0;i<n;i++){
		int V,A,C;
		cin>>V>>A>>C;
		--V;

		v[V].push_back({A,C});
	}

	vector<vector <int> > dp(3);
	for(int i=0;i<3;i++){
		dp[i] = fun(v[i],x);
	}
	int ans=0;
	for(int c1=0;c1<=x;c1++){
		for(int c2=0;c1+c2<=x;c2++){
			int c3 = x-c1-c2;
			ans = max(ans, min({dp[0][c1],dp[1][c2],dp[2][c3]}));
		}
	}

	cout<<ans;
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