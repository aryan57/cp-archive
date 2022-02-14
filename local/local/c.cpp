/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/darwin/13-febcontest4/c.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/darwin/13-febcontest4/c.cpp
*/
#include <bits/stdc++.h>
using namespace std;
#define int long long
typedef long long ll;
typedef vector<int> vi;
typedef pair<int, int> pi;
#define F first
#define S second
#define PB push_back 3
const int maxn = 1e6 + 5;
const int inf = 1e18;

const int mxn = 71;
int n,m, k, q, path[mxn][mxn], dp[mxn][mxn][mxn];

signed main() {

	// freopen("input2.txt","r",stdin);
	// freopen("output.txt","w",stdout);

    cin >> n >> m;

    memset(path, 0x3f, sizeof path);
	memset(dp, 0x3f, sizeof dp);


    for (int i= 1; i <=n; i++) {
        path[i][i] = 0;
    }
    for (int i =0; i <m; i++) {
        int a,b,t; cin >> a >> b >> t;
        path[a][b] = min(path[a][b], t);
        dp[1][a][b] = min(dp[1][a][b], t);
    }
    cin >> k >> q;
    k = min(k, n);
    for (int i= 1; i <=k; i++) {
        for (int b = 1; b <=n; b++) {
            dp[i][b][b] = 0;
        }
    }

    for (int b = 2; b <=k; b++) {
        for (int a = 1; a <=n; a++) {
            for (int i= 1; i <=n; i++) {
                for (int j =1; j <=n; j++) {
                    dp[b][i][j] = min(dp[b][i][j], dp[b-1][i][a] + dp[1][a][j]);
                }
            }
        }
    }

    
    while (q--) {
        int a,b; cin >> a >> b;
        if (dp[k][a][b] >= inf) cout << -1 << "\n";
        else cout << dp[k][a][b] << "\n";
    }

}