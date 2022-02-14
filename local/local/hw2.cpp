/*
	group : local
	name : hw2.cpp
	srcPath : /home/aryan/Dropbox/Documents from PC/free/darwin/13-febcontest4/hw2.cpp
	url : /home/aryan/Dropbox/Documents from PC/free/darwin/13-febcontest4/hw2.cpp
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


int n,m, k, q, path[71][71], minRoutes[71][71];

signed main() {

    // freopen("input2.txt","r",stdin);
	// freopen("output.txt","w",stdout);

    cin >> n >> m;
    memset(path, 0x3f, sizeof path);
    memset(minRoutes, 0x3f, sizeof minRoutes);

    // for(int i=0;i<71;i++)for(int j=0;j<71;j++){
    //     minRoutes[i][j]=inf;
    //     path[i][j]=inf;
    // }

    for (int i= 1; i <=n; i++) {
        path[i][i] = minRoutes[i][i] = 0;
    }
    for (int i =0; i <m; i++) {
        int a,b,t; cin >> a >> b >> t;
        path[a][b] = min(path[a][b], t);
        minRoutes[a][b] = 1;
    }
    cin >> k >> q;
    for (int a = 1; a <=n; a++) {
        for (int i= 1; i <=n; i++) {
            for (int j =1; j <=n; j++) {
                if (minRoutes[i][a] + minRoutes[a][j] > k) continue;
                if (path[i][j] > path[i][a] + path[a][j] ) {
                    path[i][j] = path[i][a] + path[a][j]; minRoutes[i][j] =  minRoutes[i][a] + minRoutes[a][j] ;
                }
            }
        }
    }


    while (q--) {
        int a,b; cin >> a >> b;
        if (path[a][b] >= inf) cout << -1 << "\n";
        else cout << path[a][b] << "\n";
    }

}
