/*
	group : Codeforces - Codeforces Round #753 (Div. 3)
	name : D. Blue-Red Permutation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Blue_Red_Permutation.cpp
	url : https://codeforces.com/contest/1607/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 20:59:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> v(n);
	for(int &x : v)cin>>x;

	string s;
	cin>>s;

	multiset<int> r,b;

	for(int i=0;i<n;i++){
		if(s[i]=='R')r.insert(v[i]);
		else b.insert(v[i]);
	}

	int L=1;
	int R=n;

	while (L<=R)
	{
		if(!r.empty() && *r.rbegin() > R){
			cout<<"NO\n";
			return;
		}

		if(!b.empty() && *b.begin() < L){
			cout<<"NO\n";
			return;
		}

		if(!r.empty() && *r.rbegin() == R){
			auto it=r.end();
			it--;
			r.erase(it);
			R--;
			continue;
		}

		if(!b.empty() && *b.begin() == L){
			b.erase(b.begin());
			L++;
			continue;
		}

		if(r.size() > b.size() && !r.empty()){
			auto it=r.end();
			it--;
			r.erase(it);
			R--;
			continue;
		}

		if(r.size() <= b.size() && !b.empty()){

			b.erase(b.begin());
			L++;
			continue;
		}

		cout<<"NO\n";
		return;
	}

	cout<<"YES\n";
	
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
//	parsed : 02-November-2021 20:59:01 IST