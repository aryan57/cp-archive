/**
 *    author:  Aryan Agarwal
 *    created: 14.05.2022 09:13:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> cnt(n),a(n),b(n);
	vector<set<int>> pos(n);
	for(int i=0;i<n;i++){
		cin>>a[i];
		--a[i];
		pos[a[i]].insert(i);
		cnt[i]=1;
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
		--b[i];
	}
	int start=0;
	for(int i=0;i<n;i++){
		if(pos[b[i]].empty()){
			cout<<"NO\n";
			return;
		}
		int ind = *pos[b[i]].begin();

		for(int j=start;j<ind;j++){
			auto otherind = pos[a[j]].upper_bound(ind);
			if(otherind==pos[a[j]].end()){
				cout<<"NO\n";
				return;
			}
			assert(*pos[a[j]].begin()==j);
			pos[a[j]].erase(pos[a[j]].begin());
			cnt[*otherind]+=cnt[j];
			cnt[j]=0;
		}

		assert(cnt[ind]>=1);
		if(cnt[ind]==1){
			cnt[ind]=0;
			pos[b[i]].erase(pos[b[i]].begin());
			start=ind+1;
		}else{
			cnt[ind]--;
			start=ind;
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