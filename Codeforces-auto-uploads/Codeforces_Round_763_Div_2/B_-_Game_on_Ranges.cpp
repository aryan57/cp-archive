/*
	group : Codeforces - Codeforces Round #763 (Div. 2)
	name : B. Game on Ranges.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Game_on_Ranges.cpp
	url : https://codeforces.com/contest/1623/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.12.2021 19:19:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	for(auto &p : v){
		cin>>p.first>>p.second;
	}
	sort(v.begin(),v.end(),[](pair <int,int> a,pair <int,int> b){
		return a.second-a.first < b.second-b.first;
	});

	bool pre[n+1][n+1]={};
	vector< vector<int> > ans;
	for(auto p : v){
		for(int d=p.first;d<=p.second;d++){
			bool x=false;
			bool y=false;

			if(p.first<=d-1){
				if(pre[p.first][d-1])x=true;
			}else x=true;
			if(d+1<=p.second){
				if(pre[d+1][p.second])y=true;
			}else y=true;

			if(x && y){
				if(p.first<=d-1){
					pre[p.first][d-1]=false;
				}
				if(d+1<=p.second){
					pre[d+1][p.second]=false;
				}
				ans.push_back({p.first,p.second,d});
				pre[p.first][p.second]=true;
				break;
			}
		}
	}

	for(auto v : ans){
		for(int x : v)cout<<x<<" ";
		cout<<"\n";
	}
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
//	parsed : 28-December-2021 19:12:26 IST