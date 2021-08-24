/*
	group : Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
	name : C. Deep Down Below.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Deep_Down_Below.cpp
	url : https://codeforces.com/contest/1561/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 24.08.2021 20:41:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 2e18;

bool comp(const vector<int> &a,const vector<int> &b){
	return a[a[0]+1]<b[b[0]+1];
}

void solve()
{
	int n;
	cin>>n;
	vector<int> sz(n);
	vector<vector<int>> v(n);

	for(int i=0;i<n;i++){
		int k;
		cin>>k;
		vector<int> z(k+2);
		z[0]=k;
		int mx=-inf;

		for(int j=1;j<=k;j++){
			cin>>z[j];
			mx=max(mx,z[j] - (j-1));
		}

		z[k+1]=mx;
		
		v[i]=z;
	}

	sort(v.begin(),v.end(),comp);

	int l=0;
	int r=inf;
	int ans=inf;

	while(l<=r){
		int m=(l+r)/2;
		int mid=m;
		bool ok = true;

		for(auto t : v){
			if(m<=t[t[0]+1]){
				ok=false;
				break;
			}
			m+=t[0];
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
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 24-August-2021 20:36:49 IST