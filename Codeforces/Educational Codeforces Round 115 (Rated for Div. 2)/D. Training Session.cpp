/*
	group : Codeforces - Educational Codeforces Round 115 (Rated for Div. 2)
	name : D. Training Session.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Training_Session.cpp
	url : https://codeforces.com/contest/1598/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.10.2021 10:31:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int nc3(int n){
	if(n<3)return 0;
	return ((n-2)*(n-1)*n)/6;
}
int nc2(int n){
	if(n<2)return 0;
	return ((n-1)*n)/2;
}

void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	map<pair <int,int> ,int> mp;

	int cx[n+1]={};
	int cy[n+1]={};

	vector<int> x[n+1];

	for(pair <int,int> &p : v){
		cin>>p.first>>p.second;
		x[p.first].push_back(p.second);
		mp[p]++;
		cx[p.first]++;
		cy[p.second]++;
	}

	for(int i=1;i<=n;i++){
		sort(x[i].begin(),x[i].end());
	}

	int ans=nc3(n);

	for(auto p : mp){
		ans-=nc2(p.second)*(n-2);
	}

	for(int i=1;i<=n;i++){
		int z=x[i].size();
		for(int y : x[i]){

			int cnty=mp[{i,y}];

			int remy=cy[y]-cnty;

			assert(cnty>=1 && remy>=0);

			ans-=(remy)*(z-cnty);
		}
	}



	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 22-October-2021 10:27:03 IST