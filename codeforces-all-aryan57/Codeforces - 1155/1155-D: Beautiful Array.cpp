//https://codeforces.com/contest/1155/problem/D

#include <bits/stdc++.h>

using namespace std;

#define forn(i, n) for(int i = 0; i < int(n); i++) 

typedef long long li;

const int N = 300 * 1000 + 13;
const li INF64 = 1e18;

int n, x;
int a[N];

li dp[N][3][3];

int main() {
	scanf("%d%d", &n, &x);
	forn(i, n) scanf("%d", &a[i]);
	
	forn(i, n + 1) forn(j, 3) forn(k, 3)
		dp[i][j][k] = -INF64;
	
	dp[0][0][0] = 0;
	forn(i, n + 1) forn(j, 3) forn(k, 3){
		if (k < 2)
			dp[i][j][k + 1] = max(dp[i][j][k + 1], dp[i][j][k]);
		if (j < 2)
			dp[i][j + 1][k] = max(dp[i][j + 1][k], dp[i][j][k]);
		if (i < n)
			dp[i + 1][j][k] = max(dp[i + 1][j][k], dp[i][j][k] + (j == 1 ? a[i] : 0) * li(k == 1 ? x : 1));
	}
	
	printf("%lld\n", dp[n][2][2]);
}
