/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 18:07:10 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n=3;
	vector <int> h(n),w(n);
	for(int &x : h)cin>>x;
	for(int &x : w)cin>>x;

	int cnt=0;

	for(int a=1;a<=30;a++){
		for(int b=1;b<=30;b++){
			for(int c=1;c<=30;c++){
				for(int d=1;d<=30;d++){
					int g[4][4]={};
					g[1][1]=a;
					g[1][3]=b;
					g[3][1]=c;
					g[3][3]=d;

					g[1][2] = h[0]-a-b;
					g[3][2] = h[2]-c-d;

					g[2][1] = w[0]-g[1][1]-g[3][1];
					g[2][2] = w[1]-g[1][2]-g[3][2];
					g[2][3] = w[2]-g[1][3]-g[3][3];

					bool ok = true;

					for(int i=1;i<=3;i++){
						for(int j=1;j<=3;j++){
							if(g[i][j]<=0){
								ok=false;
								break;
							}
						}
					}

					if(g[2][1]+g[2][2]+g[2][3]!=h[1])ok=false;

					if(ok)cnt++;
				}
			}
		}
	}

	cout<<cnt;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}