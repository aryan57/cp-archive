/*
	group : AtCoder - AtCoder Beginner Contest 218
	name : D - Rectangles.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Rectangles.cpp
	url : https://atcoder.jp/contests/abc218/tasks/abc218_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 11.09.2021 18:05:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<pair<int,int> > v(n);
	map<pair <int,int> ,bool> mp;
	for(int i=0;i<n;i++)
	{
		cin>>v[i].first>>v[i].second;
		mp[v[i]]=true;
	}

	int ans=0;

	for(int i=0;i<n;i++)
	{
		for(int j=i+1;j<n;j++)
		{
			pair <int,int> p1={min(v[i].first,v[j].first),min(v[i].second,v[j].second)};
			pair <int,int> p2={min(v[i].first,v[j].first),max(v[i].second,v[j].second)};
			pair <int,int> p3={max(v[i].first,v[j].first),min(v[i].second,v[j].second)};
			pair <int,int> p4={max(v[i].first,v[j].first),max(v[i].second,v[j].second)};

			set<pair <int,int> > s;
			s.insert(p1);
			s.insert(p2);
			s.insert(p3);
			s.insert(p4);

			if(s.size()==4)
			{
				bool ok = true;

				if(ok){
					if(!mp[p1])ok=false;
				}
				if(ok){
					if(!mp[p2])ok=false;
				}
				if(ok){
					if(!mp[p3])ok=false;
				}
				if(ok){
					if(!mp[p4])ok=false;
				}
			if(ok)ans++;
			}

		}
	}

	cout<<ans/2;
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
//	parsed : 11-September-2021 18:05:30 IST