/*
	group : AtCoder - AtCoder Beginner Contest 217
	name : D - Cutting Woods.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Cutting_Woods.cpp
	url : https://atcoder.jp/contests/abc217/tasks/abc217_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 04.09.2021 22:23:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int l,q;
	cin>>l>>q;

	set<int> s;
	s.insert(0);
	s.insert(l);

	while(q--){
		int c,x;
		cin>>c>>x;
		if(c==1)s.insert(x);
		else{
			auto it=s.lower_bound(x);
			assert(it!=s.begin());
			int ans=*it;
			it--;
			ans-=*it;
			cout<<ans<<"\n";
		}
	}
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
//	parsed : 04-September-2021 22:22:01 IST