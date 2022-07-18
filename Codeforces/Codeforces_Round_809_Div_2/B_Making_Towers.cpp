/**
 *    author:  Aryan Agarwal
 *    created: 18.07.2022 20:22:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> ans(n);

	vector <int> pos[n];
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		--x;
		pos[x].push_back(i);
	}

	for(int i=0;i<n;i++){
		
		const vector <int> &v = pos[i];
		if(v.empty())continue;
		int t=1;

		for(int i=1;i<v.size();i++){
			if((v[i]-v[i-1])%2){
				t++;
			}
		}
		ans[i]=t;
	}

	for(int x : ans)cout<<x<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}