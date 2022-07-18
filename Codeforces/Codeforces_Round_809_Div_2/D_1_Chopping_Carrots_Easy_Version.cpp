/**
 *    author:  Aryan Agarwal
 *    created: 18.07.2022 20:59:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n,k;
	cin>>n>>k;

	
	set <int> val;
	vector< set<int> > values(n);

	for(int i=0;i<n;i++){
		int a;
		cin>>a;
		for(int j=1;j<=k;j++){
			val.insert(a/j);
			values[i].insert(a/j);
		}
	}

	int z=val.size();
	int ans=300000;

	for(int temp : val){
		bool ok = true;
		int mx=temp;
		for(int j=0;j<n;j++){
			auto it = values[j].lower_bound(temp);
			if(it==values[j].end()){
				ok=false;
				break;
			}
			mx=max(mx,*it);
		}
		if(ok)
		ans=min(ans,mx-temp);
	}

	cout<<ans<<"\n";
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