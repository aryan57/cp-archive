/**
 *    author:  Aryan Agarwal
 *    created: 01.02.2025 17:35:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<string> s(n),t(m);
	for(string &x: s)cin>>x;
	for(string &x: t)cin>>x;

	for(int a=0;a<n;a++){
		for(int b=0;b<n;b++){
			bool ok = true;

			for(int i=0;i<m;i++){
				for(int j=0;j<m;j++){
					if(a+i==n){
						ok = false;
						break;
					}
					if(b+j==n){
						ok = false;
						break;
					}

					if(s[a+i][b+j]!=t[i][j]){
						ok=false;
						break;
					}
				}
			}

			if(ok){
				cout<<a+1<<" "<<b+1<<"\n";
				return;
			}
		}
	}
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