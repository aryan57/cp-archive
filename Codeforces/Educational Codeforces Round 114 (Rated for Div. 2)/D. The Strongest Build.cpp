/*
	group : Codeforces - Educational Codeforces Round 114 (Rated for Div. 2)
	name : D. The Strongest Build.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_The_Strongest_Build.cpp
	url : https://codeforces.com/contest/1574/problem/D#
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.09.2021 22:37:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

vector< vector<int> > a(10);
int n;

int sum(const vector<int> &v) {
	int s=0;
	for(int i=0;i<n;i++){
		s+=a[i][v[i]-1];
	}
	return s;
}

void solve()
{
	cin>>n;
	vector <int> c(n);
	map<vector <int> ,bool> mp;
	for(int i=0;i<n;i++)
	{
		cin>>c[i];
		a[i].resize(c[i]);
		for(auto &aij : a[i])cin>>aij;
	}

	int m;
	cin>>m;
	while (m--)
	{
		vector <int> v(n);
		for(int & vi : v)cin>>vi;
		mp[v]=true;
	}

	set<pair <int,vector <int> >,greater<> > s;
	s.insert({sum(c),c});

	while (!s.empty())
	{
		auto v = s.begin()->second;
		s.erase(s.begin());

		if(!mp[v]){
			for(int x : v){
				cout<<x<<" ";
			}
			cout<<"\n";
			return;
		}

		for(int i=0;i<n;i++){
			if(v[i]==1)continue;
			v[i]--;
			s.insert({sum(v),v});
			v[i]++;
		}

	}
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}