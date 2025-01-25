/**
 *    author:  Aryan Agarwal
 *    created: 25.01.2025 17:30:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	n=5;
	vector<int> v(n);
	for(int &x : v)cin>>x;

	vector<int> sorted = {1,2,3,4,5};

	for(int i=1;i<n;i++){
		swap(v[i],v[i-1]);

		if(v==sorted){
			cout<<"Yes\n";
			return;
		}

		swap(v[i],v[i-1]);
	}

	cout<<"No\n";
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