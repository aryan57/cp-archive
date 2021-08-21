/*
	group : AtCoder - AtCoder Beginner Contest 215
	name : B - log2(N).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_log2_N_.cpp
	url : https://atcoder.jp/contests/abc215/tasks/abc215_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.08.2021 17:31:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int k=0;
	int pw=1;
	int ans=0;
	while(pw<=n){
		ans=k;
		k++;
		pw*=2;
	}

	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 21-August-2021 17:30:55 IST