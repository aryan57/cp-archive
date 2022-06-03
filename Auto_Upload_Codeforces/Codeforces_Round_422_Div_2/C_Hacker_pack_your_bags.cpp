/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 11:51:16 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 2e18;

struct trip {
	int l,r,w;
};

struct cmp {
	bool operator()(const trip& x, const trip& y) const {
		if(x.l!=y.l)return x.l<y.l;
		return x.r<y.r;
	}
};

const int mxn = 2e5;

void solve()
{
	int n,x;
	cin>>n>>x;
	int ans=inf;
	vector<trip> v(n);
	for(trip &t : v){
		cin>>t.l>>t.r>>t.w;
	}

	sort(v.begin(),v.end(),cmp());
	using pii = pair<int,int>;
	vector<multiset<pii>> trips(mxn+1);
	vector<int> mn(mxn+1,inf);

	for(auto t : v){
		int ind = x-(t.r-t.l+1);
		if(ind<=0)continue;

		while(!trips[ind].empty() && trips[ind].begin()->first < t.l){
			mn[ind] = min(mn[ind],trips[ind].begin()->second);
			trips[ind].erase(trips[ind].begin());
		}

		ans = min(ans,mn[ind]+t.w);

		trips[t.r-t.l+1].insert({t.r,t.w});
	}

	if(ans==inf)ans=-1;
	cout<<ans;
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