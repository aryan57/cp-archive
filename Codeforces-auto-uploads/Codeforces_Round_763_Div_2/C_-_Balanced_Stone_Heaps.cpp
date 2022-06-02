/*
	group : Codeforces - Codeforces Round #763 (Div. 2)
	name : C. Balanced Stone Heaps.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Balanced_Stone_Heaps.cpp
	url : https://codeforces.com/contest/1623/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.12.2021 19:59:22 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];

	const int INF = 2e18;
	int l=0,r=INF,ans=0;
	while (l<=r)
	{
		int m=(l+r)/2;
		bool ok = true;
		vector <int> v(a);
		
		for(int i=n;i>=3;i--){
			int ex=max(0ll,v[i]-m);
			ex=min(ex,a[i]);
			ex=ex/3;
			v[i]-=3*ex;
			v[i-1]+=ex;
			v[i-2]+=2*ex;
		}
		
		for(int i=1;i<=n;i++){
			if(v[i]<m){
				ok=false;
				break;
			}
		}

		if(ok){
			l=m+1;
			ans=max(ans,m);
		}else{
			r=m-1;
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
//	parsed : 28-December-2021 19:59:18 IST