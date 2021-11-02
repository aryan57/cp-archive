/*
	group : Codeforces - Codeforces Round #570 (Div. 3)
	name : D. Candy Box (easy version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Candy_Box_easy_version_.cpp
	url : https://codeforces.com/contest/1183/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 19:40:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	vector <int> cnt(n+1);
	for(int &x : v){
		cin>>x;
		cnt[x]++;
	}

	sort(cnt.begin(),cnt.end(),greater<>());

	int ans=cnt[0];
	int mx=cnt[0];

	for(int i=1;i<n && mx;i++){
		if(cnt[i]>=mx)
			--mx;
		else
			mx=cnt[i];
		ans+=mx;
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
//	parsed : 02-November-2021 17:59:50 IST