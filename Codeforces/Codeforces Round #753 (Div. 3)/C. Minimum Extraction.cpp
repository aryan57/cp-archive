/*
	group : Codeforces - Codeforces Round #753 (Div. 3)
	name : C. Minimum Extraction.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Minimum_Extraction.cpp
	url : https://codeforces.com/contest/1607/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 20:46:40 IST
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

	sort(v.begin(),v.end());

	int ans=v[0];

	for(int i=1;i<n;i++){
		ans=max(ans,v[i]-v[i-1]);
	}

	cout<<ans<<"\n";
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
//	parsed : 02-November-2021 20:46:36 IST