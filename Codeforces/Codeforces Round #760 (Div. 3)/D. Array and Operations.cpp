/*
	group : Codeforces - Codeforces Round #760 (Div. 3)
	name : D. Array and Operations.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Array_and_Operations.cpp
	url : https://codeforces.com/contest/1618/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.12.2021 21:06:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	int s=0;
	vector <int> v(n);
	for(int &x : v){
		cin>>x;
	}
	sort(v.begin(),v.end(),greater<>());

	for(int i=0;i<k;i++){
		s+=v[i+k]/v[i];
	}
	for(int i=2*k;i<n;i++){
		s+=v[i];
	}
	cout<<s<<"\n";
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
//	parsed : 14-December-2021 20:53:46 IST