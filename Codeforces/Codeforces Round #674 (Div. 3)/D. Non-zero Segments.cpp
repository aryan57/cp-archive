/*
	group : Codeforces - Codeforces Round #674 (Div. 3)
	name : D. Non-zero Segments.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Non_zero_Segments.cpp
	url : https://codeforces.com/problemset/problem/1426/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 11:27:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n+1),pre(n+1);
	int cnt=0;
	int last=0;
	unordered_map<int,int> mp;
	mp[0]=1;
	for(int i=1;i<=n;i++){
		cin>>v[i];
		pre[i]=pre[i-1]+v[i];

		if(mp[pre[i]]==1){
			cnt++;
			while(last<i-1){
				mp[pre[last]]=0;
				last++;
			}
		}
		assert(mp[pre[i]]==0);
		mp[pre[i]]=1;
	}

	cout<<cnt;
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
//	parsed : 15-August-2021 11:25:35 IST