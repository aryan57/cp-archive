/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 21:24:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <bitset<3000>> v(n);
	for(int i=0;i<n;i++){
		for(int j=0;j<n;j++){
			char c;
			cin>>c;
			v[i][j]=c-'0';
		}
	}

	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(!v[i][j])continue;
			cnt+=(v[i]&v[j]).count();
		}
	}
	cout<<cnt/3;
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