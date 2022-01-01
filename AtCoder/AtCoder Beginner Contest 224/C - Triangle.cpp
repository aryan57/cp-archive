/*
	group : AtCoder - AtCoder Beginner Contest 224
	name : C - Triangle?.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Triangle_.cpp
	url : https://atcoder.jp/contests/abc224/tasks/abc224_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 17:35:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<pair<int,int> > v(n);

	for(pair <int,int>  &p : v){
		cin>>p.first>>p.second;
	}
	int cnt=0;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if((v[k].second-v[j].second)*(v[j].first-v[i].first)!=(v[k].first-v[j].first)*(v[j].second-v[i].second))cnt++;
			}
		}
	}

	cout<<cnt;
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
//	parsed : 23-October-2021 17:34:53 IST