/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 15:08:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	vector <int> pos[2];
	for(int i=0;i<n;i++){
		
		int id = (s[i]=='L'?0:1);
		pos[id].push_back(i);
	}

	vector <int> cnt(n);
	int tot = 1e5;
	for(int i=0;i<n;i++){

		int lef=i;
		int rig=-1;

		if(s[i]=='R'){
			int next = *upper_bound(pos[0].begin(),pos[0].end(),i);
			lef=i;
			rig=next;


			assert(lef<rig);

			int req = rig-lef;
			int rem = tot-req;
			assert(rem>=0);

			if(rem%2)cnt[rig-1]++;
			else cnt[rig]++;
		}
		if(s[i]=='L'){
			auto it = lower_bound(pos[1].begin(),pos[1].end(),i);
			it--;
			lef=*it;
			rig=i;


			assert(lef<rig);

			int req = rig-lef;
			int rem = tot-req;
			assert(rem>=0);

			if(rem%2)cnt[lef+1]++;
			else cnt[lef]++;
		}

	}

	for(int x : cnt)cout<<x<<" ";
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