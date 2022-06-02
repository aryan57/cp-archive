/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 21:47:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<pair<int,int> > v(n);
	int s=0;
	int aa=0;
	int bb=0;
	vector <int> a(n);
	vector <int> b(n);
	for(int i=0;i<n;i++){
		cin>>a[i]>>b[i];
		aa+=a[i];
		bb+=b[i];
		pair <int,int> x1={0,a[i]};
		pair <int,int> x2={a[i]-m,a[i]+b[i]-m};
		v[i]={max(x1.first,x2.first),min(x1.second,x2.second)};
		assert(v[i].first<=v[i].second);
		s+=v[i].first;
	}
	
	int extra=(aa+bb-n*m)/2 - s;
	extra=max(0ll,extra);
	for(int i=0;i<n;i++){
		int can=v[i].second-v[i].first;
		int did=min(can,extra);
		extra-=did;
		v[i].first+=did;
		s+=did;
	}
	
	vector<pair<int,int> > ans(n);
	int xa=0;
	int xb=0;

	for(int i=0;i<n;i++){
		ans[i] = {a[i]-v[i].first,m-a[i]+v[i].first};
		xa+=a[i] - ans[i].first;
		xb+=b[i] - ans[i].second;
	}

	cout<<abs(xa-xb)<<"\n";
	for(auto p : ans)cout<<p.first<<" "<<p.second<<"\n";
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
//	parsed : 02-November-2021 21:47:23 IST