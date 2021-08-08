/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 06.08.2021 17:59:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n=s.size();

	s='#'+s;

	vector<vector<int>> pre(2,vector<int> (n+1,0));

	for(int i=1;i<=n;i++)
	{

		pre[0][i]=pre[0][i-1];
		pre[1][i]=pre[1][i-1];

		if(i%2){
			pre[0][i]+=(s[i]!='w'?1:0);
			pre[1][i]+=(s[i]!='b'?1:0);
		}else{
			pre[0][i]+=(s[i]!='b'?1:0);
			pre[1][i]+=(s[i]!='w'?1:0);
		}
	}
	int ans=1e18;
	for(int i=1;i<=n;i++)
	{
		int l=n-i;

		for(int bit : {0,1}){
			int cnt=0;
			cnt+=pre[bit][i];
			int bit2=bit^((l%2)^(i%2));

			cnt+=pre[bit2][n]-pre[bit2][i];

			ans=min(ans,cnt);
		}
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