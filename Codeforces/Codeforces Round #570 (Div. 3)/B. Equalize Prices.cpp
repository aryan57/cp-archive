/*
	group : Codeforces - Codeforces Round #570 (Div. 3)
	name : B. Equalize Prices.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Equalize_Prices.cpp
	url : https://codeforces.com/contest/1183/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 19:25:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 2e18;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> v(n);
	int l=-INF;
	int r=INF;

	while (n--)
	{
		int x;
		cin>>x;
		l=max(l,max(0ll,x-k));
		r=min(r,x+k);
	}

	if(l>r){
		cout<<"-1\n";
		return;
	}

	cout<<r<<"\n";
	

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
//	parsed : 02-November-2021 17:59:50 IST