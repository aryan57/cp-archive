/**
 *    author:  Aryan Agarwal
 *    created: 17.07.2022 17:34:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,x,y,z;
	cin>>n>>x>>y>>z;

	vector< vector<int> > v(n,vector <int> (3));

	for(int i=0;i<n;i++){
		cin>>v[i][0];
		v[i][2]=i+1;
	}
	for(int i=0;i<n;i++){
		cin>>v[i][1];
	}
	vector <int> ans;
	sort(v.begin(),v.end(),[](const auto &v1,const auto &v2){
		if(v1[0]==v2[0])return v1[2]>v2[2];
		return v1[0]<v2[0];
	});

	while (x--)
	{
		ans.push_back(v.back()[2]);
		v.pop_back();
	}
	sort(v.begin(),v.end(),[](const auto &v1,const auto &v2){
		if(v1[1]==v2[1])return v1[2]>v2[2];
		return v1[1]<v2[1];
	});

	while (y--)
	{
		ans.push_back(v.back()[2]);
		v.pop_back();
	}

	sort(v.begin(),v.end(),[](const auto &v1,const auto &v2){
		if(v1[1]+v1[0]==v2[1]+v2[0])return v1[2]>v2[2];
		return v1[1]+v1[0]<v2[1]+v2[0];
	});

	while (z--)
	{
		ans.push_back(v.back()[2]);
		v.pop_back();
	}

	sort(ans.begin(),ans.end());
	for(int x : ans)cout<<x<<"\n";
	
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