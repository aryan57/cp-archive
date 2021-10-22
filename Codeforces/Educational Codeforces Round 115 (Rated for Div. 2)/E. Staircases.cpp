/*
	group : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
	name : E. Staircases.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Staircases.cpp
	url : https://codeforces.com/contest/1598/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.10.2021 11:16:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

template<typename A, typename B> ostream& operator<<(ostream &os, const pair<A, B> &p) { return os << '(' << p.first << ", " << p.second << ')'; }
template<typename T_container, typename T = typename enable_if<!is_same<T_container, string>::value, typename T_container::value_type>::type> ostream& operator<<(ostream &os, const T_container &v) { os << '{'; string sep; for (const T &x : v) os << sep << x, sep = ", "; return os << '}'; }
void dbg_out() { cerr << endl; }
template<typename Head, typename... Tail> void dbg_out(Head H, Tail... T) { cerr << ' ' << H; dbg_out(T...); }
#ifndef ONLINE_JUDGE
#define dbg(...) cerr << "(" << #__VA_ARGS__ << "):", dbg_out(__VA_ARGS__)
#else
#define dbg(...)
#endif

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;

	int dp2[n+1][m+1][2]={};
	int ans=n*m;

	for(int i=1;i<=n;i++){
		for(int j=1;j<=m;j++){
			
			if(j+1<=m)dp2[i][j+1][1]+=dp2[i][j][0]+1;
			if(i+1<=n)dp2[i+1][j][0]+=dp2[i][j][1]+1;

			ans+=dp2[i][j][0];
			ans+=dp2[i][j][1];
			
			string s = to_string(dp2[i][j][0]+dp2[i][j][1]);
			s="0000"+s;
			s=s.substr(s.size()-2,2);
			cout<<s<<" ";
		}
		cout<<"\n";
	}



	

	// int dp[n+1][m+1][2]={};
	// g[4][7]=1;
	// for(int i=1;i<=n;i++){
	// 	for(int j=1;j<=m;j++){
	// 		if(g[i][j]==0){
	// 			if(j+1<=m)dp[i][j+1][1]+=dp[i][j][0]+1;
	// 			if(i+1<=n)dp[i+1][j][0]+=dp[i][j][1]+1;
	// 		}
	// 		string s = to_string(dp[i][j][0]+dp[i][j][1]);
	// 		s="0000"+s;
	// 		s=s.substr(s.size()-2,2);
	// 		cout<<s<<" ";
	// 	}
	// 	cout<<"\n";
	// }
	int g[n+1][m+1]={};
	while (q--)
	{
		int x,y;
		cin>>x>>y;

		g[x][y]^=1;

		int z=1;

		z+=dp2[x][y][0];
		z+=dp2[x][y][1];

		z+=(m-y)*(dp2[x][y][0]+1);
		z+=(n-x)*(dp2[x][y][1]+1);
		z+=(n-x)*(m-y)*(dp2[x][y][1]+dp2[x][y][0]+2);

		dbg(q,z);


		if(g[x][y]==0)ans+=z;
		else ans-=z;

		cout<<ans<<"\n";
	}
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 22-October-2021 11:11:38 IST