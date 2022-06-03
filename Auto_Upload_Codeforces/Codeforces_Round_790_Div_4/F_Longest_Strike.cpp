/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 20:34:16 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf  = 2e18;

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	map<int,int> mp;
	set<int> s;
	for(int i=0;i<n;i++){
		cin>>v[i];
		mp[v[i]]++;
		if(mp[v[i]]>=k)s.insert(v[i]);
	}
	if(s.empty()){
		cout<<"-1\n";
		return;
	}

	s.insert(inf);

	// dbg(s);

	int mx=0;
	int l=-1;int r=-1;

	l=r=*s.begin();
	mx=0;
	int prev=l;
	int prevl=l;
	auto it = s.begin();
	it++;
	while (it!=s.end())
	{
		// dbg(*it,l,r,mx);
		if(*it!=prev+1){
			if(mx < prev-prevl){
				mx = prev-prevl;
				l=prevl;
				r=prev;
			}
			prevl=*it;
		}else{
			if(mx < *it-prevl){
				mx = *it-prevl;
				l=prevl;
				r=*it;
			}
		}
		prev=*it;
		it++;
	}
	
	cout<<l<<" "<<r<<"\n";
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