/*
	group : Codeforces - Codeforces Round #751 (Div. 2)
	name : B. Divine Array.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Divine_Array.cpp
	url : https://codeforces.com/contest/1602/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.10.2021 21:58:23 IST
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

	vector< vector<int> > all;
	all.push_back(v);
	while (true)
	{
		vector <int> temp(n);
		vector <int> cnt(n+1);

		for(int x : v)cnt[x]++;
		for(int i=0;i<n;i++){
			temp[i]=cnt[v[i]];
		}

		all.push_back(temp);
		if(temp==v)break;
		swap(temp,v);
	}

	int q;
	cin>>q;
	while (q--)
	{
		int x,k;
		cin>>x>>k;
		--x;
		if(k<all.size()){
			cout<<all[k][x];
		}else{
			cout<<all.back()[x];
		}
		cout<<"\n";
	}
	
	
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
//	parsed : 29-October-2021 21:57:59 IST