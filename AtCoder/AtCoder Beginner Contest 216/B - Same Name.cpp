/*
	group : AtCoder - AtCoder Beginner Contest 216
	name : B - Same Name.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Same_Name.cpp
	url : https://atcoder.jp/contests/abc216/tasks/abc216_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.08.2021 17:34:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<pair<string,string>> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].first>>v[i].second;
	}

	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			if(v[i]==v[j]){
				cout<<"Yes";
				return;
			}
		}
	}

	cout<<"No";
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