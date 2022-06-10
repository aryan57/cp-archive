/**
 *    author:  Aryan Agarwal
 *    created: 03.06.2022 22:11:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> cnt(26);
	for(int i=0;i<=2*n;i++){
		string s;
		cin>>s;
		for(char &x : s)cnt[x-'a']++;
	}
	for(int i=0;i<26;i++){
		if(cnt[i]&1)cout<<char('a'+i);
	}
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}