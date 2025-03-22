/**
 *    author:  Aryan Agarwal
 *    created: 01.03.2025 17:37:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<string> v(n,string(n,'?'));

	for(int i=1;i<=n;i++){
		int j = n+1-i;
		if(i>j)break;

		for(int x=i;x<=j;x++){
			for(int y=i;y<=j;y++){
				v[x-1][y-1]=(i&1)?'#':'.';
			}
		}
	}

	for(auto &x : v)cout<<x<<"\n";

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