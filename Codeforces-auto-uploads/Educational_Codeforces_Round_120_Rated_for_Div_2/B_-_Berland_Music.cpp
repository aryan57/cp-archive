/*
	group : Codeforces - Educational Codeforces Round 120 (Rated for Div. 2)
	name : B. Berland Music.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Berland_Music.cpp
	url : https://codeforces.com/contest/1622/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.12.2021 20:36:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	string s;
	cin>>s;

	vector <int> one,zero;

	for(int i=0;i<n;i++){
		if(s[i]=='1')one.push_back(i);
		else zero.push_back(i);
	}

	sort(one.begin(),one.end(),[&](int a,int b){
		return v[a] > v[b];
	});
	sort(zero.begin(),zero.end(),[&](int a,int b){
		return v[a] > v[b];
	});

	vector<int> ans(n);
	int x=n;
	for(int i : one){
		ans[i]=x--;
	}
	for(int i : zero){
		ans[i]=x--;
	}
	for(int x : ans)cout<<x<<" ";
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
//	parsed : 27-December-2021 20:36:26 IST