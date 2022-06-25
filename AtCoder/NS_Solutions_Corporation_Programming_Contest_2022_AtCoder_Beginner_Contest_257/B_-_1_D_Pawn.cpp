/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 17:36:02 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k,q;
	cin>>n>>k>>q;

	vector <int> pos(k);
	vector <int> cnt(n);

	for(int i=0;i<k;i++){
		int a;
		cin>>a;
		--a;
		cnt[a]++;
		pos[i]=a;
	}

	while (q--)
	{
		int l;
		cin>>l;--l;
		if(pos[l]==n-1 || cnt[pos[l]+1])continue;
		cnt[pos[l]]--;
		cnt[pos[l]+1]++;
		pos[l]++;
	}
	
	for(int x : pos)cout<<x+1<<" ";

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}