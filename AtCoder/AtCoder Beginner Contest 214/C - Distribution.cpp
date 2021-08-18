/*
	group : AtCoder - AtCoder Beginner Contest 214
	name : C - Distribution.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Distribution.cpp
	url : https://atcoder.jp/contests/abc214/tasks/abc214_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.08.2021 17:42:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n),t(n);

	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	for(int i=0;i<n;i++){
		cin>>t[i];
	}

	vector<int> suf(n);
	multiset<int> m;
	for(int i=n-1;i>0;i--){
		if(i+1<n)suf[i]+=suf[i+1];
		suf[i]+=v[i];
		m.insert(t[i]+suf[i]);
	}
	// m.insert(t[0]);
	int add=0;
	int pre=0;
	for(int i=0;i<n;i++){

		auto it=m.begin();

		int ans=t[i];
		ans=min(ans,add + *it);
		cout<<ans<<"\n";

		if(i+1<n){
			auto it2=m.find(suf[i+1]+t[i+1]);
			assert(it2!=m.end());
			m.erase(it2);
			m.insert(t[i]-pre);
		}

		add+=v[i];
		pre+=v[i];

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
//	parsed : 14-August-2021 17:34:40 IST