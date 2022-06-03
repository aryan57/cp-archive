/**
 *    author:  Aryan Agarwal
 *    created: 10.05.2022 20:28:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;
	vector <int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
	}

	sort(v.begin()+1,v.end(),greater<>());

	for(int i=1;i<=n;i++)v[i]+=v[i-1];

	while (q--)
	{
		int x;
		cin>>x;

		auto ind = lower_bound(v.begin(),v.end(),x)-v.begin();
		if(ind==n+1){
			cout<<"-1\n";
			continue;
		}
		cout<<ind;
		cout<<"\n";

	}
	
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