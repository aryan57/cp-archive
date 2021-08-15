/*
	group : AtCoder - AtCoder Beginner Contest 214
	name : E - Packing Under Range Regulations.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Packing_Under_Range_Regulations.cpp
	url : https://atcoder.jp/contests/abc214/tasks/abc214_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 09:02:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<pair<int,int>> v(n);
	map<int,vector<int>> mp;
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		v[i]={l,r};
		mp[l].push_back(r);
	}

	
	auto it=mp.begin();
	priority_queue<int,vector<int>,greater<int>> pq;
	while(it!=mp.end()){

		int l=it->first;

		for(auto r : it->second){
			pq.push(r);
		}
		it++;

		while(!pq.empty()){
			if(l>pq.top()){
				cout<<"No\n";
				return;
			}
			pq.pop();
			l++;

			if(it!=mp.end() && l==it->first){
				for(auto r : it->second){
					pq.push(r);
				}
				it++;
			}
		}

	}
	cout<<"Yes\n";
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
//	parsed : 15-August-2021 09:02:10 IST