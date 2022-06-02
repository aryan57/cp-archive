/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 14:45:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	vector<int> v(n);
	for(int &x : v){
		cin>>x;
	}

	int l=0;
	int r=m-1;

	int ans=m-1;

	while(l<=r){
		int mid=(l+r)/2;

		bool ok = true;

		int prev=0;

		for(int i=0;i<n;i++){

			int x=v[i];
			int y=min(m-1,v[i]+mid);

			int x2=-1;
			int y2=-1;

			if(v[i]+mid>=m){
				x2=0;
				y2=(v[i]+mid)%m;
			}
			assert(y2<=y);
			if(prev>y){
				ok=false;
				break;
			}
			
			if(x2!=-1 && prev<=y2)prev=max(prev,x2);
			else prev=max(prev,x);
		
		}

		if(ok){
			ans=min(ans,mid);
			r=mid-1;
		}else{
			l=mid+1;
		}

	}

	cout<<ans<<"\n";

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 15-August-2021 14:33:40 IST