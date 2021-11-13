/*
	group : Codeforces - Codeforces Round #754 (Div. 2)
	name : B. Reverse Sort.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Reverse_Sort.cpp
	url : https://codeforces.com/contest/1605/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 13.11.2021 10:42:33 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s;
	t=s;
	sort(t.begin(),t.end());

	vector <int> v;

	for(int i=0;i<n;i++){
		if(s[i]!=t[i]){
			v.push_back(i+1);
		}
	}

	if(v.empty()){
		cout<<0;
		cout<<"\n";
		return;
	}

	cout<<1<<"\n";
	cout<<v.size()<<" ";
	for(int x : v)cout<<x<<" ";
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
//	parsed : 13-November-2021 10:42:30 IST