/*
	group : Codeforces - Educational Codeforces Round 117 (Rated for Div. 2)
	name : B. Special Permutation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Special_Permutation.cpp
	url : https://codeforces.com/problemset/problem/1612/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.11.2021 19:38:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,a,b;
	cin>>n>>a>>b;

	int ra=n/2-1;
	int rb=n/2-1;
	int ex=0;

	vector <int> v1,v2;
	v1.push_back(a);
	v2.push_back(b);
	vector <int> temp;

	for(int i=1;i<=n;i++){
		if(i==a || i==b)continue;
		if(i>a && i<b){
			temp.push_back(i);
			ex++;
			continue;
		}
		if(i<a && i>b){
			cout<<"-1\n";
			return;
		}
		if(i>a){
			if(!ra){cout<<"-1\n";return;}
			ra--;
			v1.push_back(i);
		}else{
			if(!rb){cout<<"-1\n";return;}
			rb--;
			v2.push_back(i);
		}
	}
	if(ex!=ra+rb){
		cout<<"-1\n";
		return;
	}

	for(int x : temp){
		if(v1.size()<n/2)v1.push_back(x);
		else v2.push_back(x);
	}
	for(int x : v1)cout<<x<<" ";
	for(int x : v2)cout<<x<<" ";
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
//	parsed : 28-November-2021 19:38:10 IST