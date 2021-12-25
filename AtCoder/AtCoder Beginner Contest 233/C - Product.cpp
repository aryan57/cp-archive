/*
	group : AtCoder - AtCoder Beginner Contest 233
	name : C - Product.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Product.cpp
	url : https://atcoder.jp/contests/abc233/tasks/abc233_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.12.2021 17:35:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int unsigned long long
int n,x;
const int mx = 1e5+1;
vector< vector<int> > a(mx);
vector <int> l(mx);
int cnt=0;

void dp(int ind,int pr){
	// cout<<ind<<" "<<pr<<"^\n";
	if(ind==n){if(pr==1)cnt++;return;}
	for(int i=0;i<l[ind];i++){
		if((pr%a[ind][i])==0)dp(ind+1,pr/a[ind][i]);
	}
}
void solve()
{
	cin>>n>>x;
	for(int i=0;i<n;i++){
		cin>>l[i];
		a[i].resize(l[i]);
		for(int j=0;j<l[i];j++){
			cin>>a[i][j];
		}
	}
	dp(0,x);
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
//	parsed : 25-December-2021 17:32:44 IST