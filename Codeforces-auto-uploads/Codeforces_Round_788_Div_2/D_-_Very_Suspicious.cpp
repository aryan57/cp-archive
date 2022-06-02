/**
 *    author:  Aryan Agarwal
 *    created: 06.05.2022 21:42:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int l=1;
	int r=1e9;

	int ans=r;

	while (l<=r)
	{
		int m=(l+r)/2;
		
		vector <int> v={m/3,m/3,m/3};
		int k=m%3;
		for(int i=0;i<3;i++){
			if(k){
				v[i]++;
				k--;
			}
		}

		if(v[0]*v[1]+v[1]*v[2]+v[0]*v[2] >= (n+1)/2){
			ans=min(ans,m);
			r=m-1;
		}else{
			l=m+1;
		}
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