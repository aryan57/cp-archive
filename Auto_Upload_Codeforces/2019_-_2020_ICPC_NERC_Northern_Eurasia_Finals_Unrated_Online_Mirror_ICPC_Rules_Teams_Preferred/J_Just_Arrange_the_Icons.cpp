/**
 *    author:  Aryan Agarwal
 *    created: 03.06.2022 17:07:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> cnt(n+1);
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}
	vector<int> s;
	for(int x : cnt)if(x)s.push_back(x);

	int mn = *s.begin();
	int ans = n;

	for(int sz=2;sz<=max(mn+1,2ll);sz++){
		bool ok = true;
		int tot=0;

		for(int t : s){
			if( (t+sz-1)/sz > t/(sz-1) ){
				ok=false;
				break;
			}
			tot+=(t+sz-1)/sz;
		}
		if(ok)ans=min(ans,tot);
	}
	cout<<ans<<"\n";
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