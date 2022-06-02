/**
 *    author:  Aryan Agarwal
 *    created: 30.04.2022 20:24:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n=s.size();

	vector <int> pos[26];
	int cnt[26]={};
	int tot=0;
	for(int i=0;i<n;i++){
		pos[s[i]-'a'].push_back(i);
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']==1)tot++;
	}

	for(int i=0;i<26;i++){
		for(int j=1;j<pos[i].size();j++){
			if(pos[i][j]-pos[i][j-1]!=tot){
				cout<<"NO\n";
				return;
			}
		}
	}
	cout<<"YES\n";
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