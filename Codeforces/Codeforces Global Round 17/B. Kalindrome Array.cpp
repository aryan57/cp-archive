/*
	group : Codeforces - Codeforces Global Round 17
	name : B. Kalindrome Array.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Kalindrome_Array.cpp
	url : https://codeforces.com/problemset/problem/1610/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.12.2021 18:50:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool ispali(vector <int> &t){
	int n=t.size();
	int l=0,r=n-1;
	while (l<r){
		if(t[l]!=t[r])return false;
		l++;
		r--;
	}
	return true;
}

bool check(vector <int> &v,int x){
	int n=v.size();
	vector <int> t;
	for(int z : v){
		if(z!=x)t.push_back(z);
	}
	return ispali(t);
}

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	int l=0,r=n-1;
	while (l<r)
	{
		if(v[l]!=v[r]){
			if(check(v,v[l]) || check(v,v[r]))cout<<"YES\n";
			else cout<<"NO\n";
			return;
		}
		l++;
		r--;
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
//	parsed : 16-December-2021 18:50:11 IST