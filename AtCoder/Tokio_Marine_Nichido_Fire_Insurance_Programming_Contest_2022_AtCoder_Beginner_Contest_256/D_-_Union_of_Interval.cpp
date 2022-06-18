/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 18:14:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int mxn = 2e5;

	vector <int> cnt(mxn+1);

	while (n--)
	{
		int l,r;
		cin>>l>>r;
		cnt[l]++;
		cnt[r]--;
	}

	int l=1;
	vector<pair<int,int> > ans;
	for(int i=1;i<=mxn;i++){
		cnt[i]+=cnt[i-1];
		if(cnt[i]==0){
			if(l<i){
				cout<<l<<" "<<i<<"\n";
			}
			l=i+1;
		}
	}

	// cout<<ans.size()<<"\n";
	// for(auto p : ans){
	// 	cout<<p.first<<" "<<p.second<<"\n";
	// }
	 
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