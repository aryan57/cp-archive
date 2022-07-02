#include "bits/stdc++.h"
using namespace std;
const int N = 301;
const int mod = 1e9 + 7;

int m, n, o;
string X,Y,Z;

int dp[N][N][N][3];

int dp2[N][N];
int dp3[N][N];

int add(int a , int b) {
	a += b;
	if(a >= mod) {
		a -= mod;
	}
	return a;
}

int sub(int a , int b) {
	return (a - b + mod) % mod;
}

int countNumberofWays(int dx , int dy , int mtch , int status) {
    /* 
    this function returns the total number of ways to create string C using either A 	   only, B only or both.
	*/
    
    if(mtch >= o) {
		return 1; 
	}
	if(dp[dx][dy][mtch][status] != -1)
		return dp[dx][dy][mtch][status];

	int rekt = 0;

	if(status != 2 and dx < m and X[dx] == Z[mtch]) {
		rekt = add(rekt , countNumberofWays(dx + 1 , dy , mtch + 1 , 0));
	} 
	if(status != 1 and dy < n and Y[dy] == Z[mtch]) {
		rekt = add(rekt , countNumberofWays(dx , dy + 1 , mtch + 1 , 0));
	}
	if(status != 2 and dx < m) {
		rekt = add(rekt , countNumberofWays(dx + 1 , dy , mtch , 1));
	}
	if(status != 1 and dy < n) {
		rekt = add(rekt , countNumberofWays(dx , dy + 1 , mtch , 2));
	}
	return dp[dx][dy][mtch][status] = rekt;
}

int usingOnlyFirstString(int posx , int mtch) {
    /*
    this function returns the number of ways to create string C using only string A
	*/
    
    if(mtch >= o) return 1;
	if(posx >= m) return 0;
	if(dp2[posx][mtch] != -1)
		return dp2[posx][mtch];

	int ret = usingOnlyFirstString(posx + 1 , mtch);

	if(X[posx] == Z[mtch]) {
		ret = add(ret , usingOnlyFirstString(posx + 1 , mtch + 1));
	}
	return dp2[posx][mtch] = ret;
}

int usingOnlySecondString(int posy , int mtch) {
    /* 
    this function returns the number of ways to create string C using only string B
	*/
    
    if(mtch >= o) return 1;
	if(posy >= n) return 0;
	if(dp3[posy][mtch] != -1)
		return dp3[posy][mtch];

	int ret = usingOnlySecondString(posy + 1 , mtch);

	if(Y[posy] == Z[mtch]) {
		ret = add(ret , usingOnlySecondString(posy + 1 , mtch + 1));
	}
	return dp3[posy][mtch] = ret;
}

int main() {
  ios_base :: sync_with_stdio(false);
  cin.tie(0);
  cin >> X >> Y >> Z;
  m = X.size(); n = Y.size(); o = Z.size();
  memset(dp , -1 , sizeof dp);
  memset(dp2 , -1 , sizeof dp2);
  memset(dp3 , -1 , sizeof dp3);
  int ans = countNumberofWays(0 , 0 , 0 , 0);

	cout<<ans<<"\n";

  ans = sub(ans , usingOnlyFirstString(0 , 0)); 
  ans = sub(ans , usingOnlySecondString(0 , 0));
  cout << ans << endl;
  return 0; 
}