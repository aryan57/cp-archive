/**
 *    author:  Aryan Agarwal
 *    created: 26.11.2021 16:51:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int> > v(n);
	for(int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second=i;
	}

	sort(v.begin(),v.end(),greater<>());

	int tot=0;
	vector <int> ans(n,-1);
	int id=0;
	for(int i=0;i<n;i++){
		if(i%2==0)id++;
		if(i%2==0)ans[v[i].second]=id;
		else ans[v[i].second]=-id;
		tot+=abs(2*v[i].first*id);
	}

	cout<<tot<<"\n0 ";
	for(int x : ans)cout<<x<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 26-November-2021 16:48:04 IST