/*
	group : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
	name : C. Poisoned Dagger.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Poisoned_Dagger.cpp
	url : https://codeforces.com/contest/1613/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 01.12.2021 20:39:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,h;
	cin>>n>>h;
	vector <int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
	}
	int l=(h+n-1)/n;
	int r=h;
	int ans=h;
	while (l<=r)
	{
		int m=(l+r)/2;
		int z=0;
		for(int i=1;i<n;i++){
			z+=min(m,v[i]-v[i-1]);
		}
		z+=m;
		if(z>=h){
			r=m-1;
			ans=min(ans,m);
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
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 01-December-2021 20:32:39 IST