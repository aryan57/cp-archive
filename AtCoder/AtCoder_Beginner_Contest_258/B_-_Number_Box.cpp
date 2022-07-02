/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 17:34:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long


vector <int> hx = {-1,-1,-1,0,1,1,1,0};
vector <int> hy = {-1,0,1,1,1,0,-1,-1};

void solve()
{
	int n;
	cin>>n;
	vector <string> g(n);
	for(int i=0;i<n;i++){
		cin>>g[i];
	}

	int mx=0;

	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			for(int k=0;k<8;k++){
				int x=i;
				int y=j;
				int len=n;
				int num=0;

				while (len--)
				{
					num=num*10 + (g[x][y]-'0');

					x=x+hx[k];
					y=y+hy[k];

					x%=n;x+=n;x%=n;
					y%=n;y+=n;y%=n;
				}
				

				mx=max(mx,num);
			}
		}
	}

	cout<<mx;
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