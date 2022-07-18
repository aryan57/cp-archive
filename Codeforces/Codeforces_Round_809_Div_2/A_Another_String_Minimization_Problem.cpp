/**
 *    author:  Aryan Agarwal
 *    created: 18.07.2022 20:10:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	string s(m,'B');

	vector <int> cnt(m+1);
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}

	for(int i=1;i<=m;i++){
		if(cnt[i]>0){
			cnt[i]--;
			s[i-1]='A';
		}else if(cnt[m+1-i]>0){
			cnt[m+1-i]--;
			s[i-1]='A';
		}
	}

	cout<<s<<"\n";
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