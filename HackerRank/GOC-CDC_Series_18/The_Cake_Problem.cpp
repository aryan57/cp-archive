/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 15:01:47 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second = n-i;
	}

	sort(v.begin(),v.end());
	int tot=0;

	for(int i=0;i<n;i++){
		int t = k/v[i].first;
		t=min(t,v[i].second);
		tot+=t;
		k-=t*v[i].first;
	}

	cout<<tot<<"\n";

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