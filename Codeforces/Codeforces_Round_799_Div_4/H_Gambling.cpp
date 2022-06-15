/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:50:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	map<int,vector <int> > mp;
	for(int i=1;i<=n;i++){
		cin>>v[i-1];
		mp[v[i-1]].push_back(i);
	}

	int mx=1;
	vector <int> ans = {v[0],1,1};

	for(auto &p : mp){
		int num = p.first;
		auto t = p.second;

		int tot=1;
		int l=t[0];

		for(int i=1;i<t.size();i++){
			
			int bad = t[i]-t[i-1]-1;
			if(tot-bad>0){
				tot-=bad;
				tot++;
				if(mx<tot){
					mx = tot;
					ans = {num,l,t[i]};
				}
			}else{
				tot=1;
				l=t[i];
			}
		}
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