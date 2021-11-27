/*
	group : AtCoder - NEC Programming Contest 2021(AtCoder Beginner Contest 229)
	name : D - Longest X.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Longest_X.cpp
	url : https://atcoder.jp/contests/abc229/tasks/abc229_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.11.2021 17:40:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	int k;
	cin>>k;
	int n=s.size();

	int ans=0;
	s='#'+s;
	vector <int> pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]=pre[i-1] + (s[i]=='.'?1:0);
	}
	for(int i=1;i<=n;i++){
		int l=1;
		int r=n-i+1;
		while (l<=r)
		{
			int m=(l+r)/2;
			int cnt = pre[i+m-1]-pre[i-1];
			if(cnt<=k){
				l=m+1;
				ans=max(ans,m);
			}else{
				r=m-1;
			}
		}
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
//	parsed : 27-November-2021 17:30:40 IST