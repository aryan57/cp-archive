/*
	group : AtCoder - AtCoder Beginner Contest 215
	name : F - Dist Max 2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Dist_Max_2.cpp
	url : https://atcoder.jp/contests/abc215/tasks/abc215_f
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.08.2021 18:48:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<array<int,2>> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i][0]>>v[i][1];
	}

	sort(v.begin(),v.end());
	vector<int> mn(n),mx(n);
	mn[0]=mx[0]=v[0][1];
	for(int i=1;i<n;i++){
		mn[i]=min(mn[i-1],v[i][1]);
		mx[i]=max(mx[i-1],v[i][1]);
	}

	vector<int> smn(n),smx(n);
	smn[n-1]=smx[n-1]=v[n-1][1];
	for(int i=n-2;i>=0;i--){
		smn[i]=min(smn[i+1],v[i][1]);
		smx[i]=max(smx[i+1],v[i][1]);
	}

	int ans=0;
	int l=0;
	int r=1e9;

	int inf  = 2e18;

	while(l<=r){

		int m=(l+r)/2;
		bool ok = false;

		// if(m<=10)cerr<<m<<"$\n";

		for(int i=0;i<n;i++){
			array<int,2> z;
			z[0]=v[i][0]-m;
			z[1]=-inf;
			auto it = upper_bound(v.begin(),v.end(),z)-v.begin();

			if(it!=0){
				it--;
				if(mn[it]<=v[i][1]-m || mx[it]>=v[i][1]+m){
					ok=true;
					break;
				}
			}

			{
				array<int,2> z;
				z[0]=v[i][0]+m;
				z[1]=-inf;
				auto it = lower_bound(v.begin(),v.end(),z)-v.begin();

				if(it!=n){
					if(smn[it]<=v[i][1]-m || smx[it]>=v[i][1]+m){
						ok=true;
						break;
					}
				}
			}
		}

		if(ok){
			ans=max(ans,m);
			l=m+1;
		}else{
			r=m-1;
		}

	}

	cout<<ans;
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
//	parsed : 21-August-2021 18:42:26 IST