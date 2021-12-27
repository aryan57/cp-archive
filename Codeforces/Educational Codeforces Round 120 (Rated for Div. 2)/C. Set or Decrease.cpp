/*
	group : Codeforces - Educational Codeforces Round 120 (Rated for Div. 2)
	name : C. Set or Decrease.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Set_or_Decrease.cpp
	url : https://codeforces.com/contest/1622/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.12.2021 20:51:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> v(n);
	int s=0;
	for(int &x : v){
		cin>>x;
		s+=x;
	}

	if(s<=k){
		cout<<0;
		cout<<"\n";
		return;
	}

	if(n==1){
		cout<<v[0]-k;
		cout<<"\n";
		return;
	}
	sort(v.begin(),v.end());
	int ans=s-k;
	int p=0;

	for(int i=0;i<n;i++){
		p+=v[i];
		int z=max(0ll,v[0] - ((k-p+v[0])/(n-i)));
		for(int zz=z;zz<=z+5;zz++){
			if(zz<0 || (p-v[0] + (n-i)*(v[0]-zz)>k))continue;
			if(zz)ans=min(ans,n+zz-i-1);
			else if(i+1<n && v[i+1]!=v[0])ans=min(ans,n-i-1);
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
//	parsed : 27-December-2021 20:43:20 IST