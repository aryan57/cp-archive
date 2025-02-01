/**
 *    author:  Aryan Agarwal
 *    created: 01.02.2025 17:42:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;

	vector<int> pos(n),cnt(n,1);
	iota(pos.begin(),pos.end(),0);
	int ans=0;



	while (q--){
		int op;
		cin>>op;

		if(op==1){
			int p,h;
			cin>>p>>h;
			--p;--h;

			int prev = ((cnt[pos[p]]>1)?1:0) + ((cnt[h]>1)?1:0);
			int cur = ((cnt[pos[p]]-1>1)?1:0) + ((cnt[h]+1>1)?1:0);

			cnt[pos[p]]--;
			pos[p]=h;
			cnt[h]++;

			ans -= prev;
			ans += cur;

		}else {
			cout<<ans<<"\n";
		}
	}
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}