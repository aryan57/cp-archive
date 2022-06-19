/**
 *    author:  Aryan Agarwal
 *    created: 19.06.2022 16:06:22 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	vector <int> pre(n),suf(n);

	for(int i=0;i+1<n;i++){
		if(v[i]>v[i+1])pre[i]=v[i]-v[i+1];
	}
	for(int i=n-1;i>=1;i--){
		if(v[i]>v[i-1])suf[i]=v[i]-v[i-1];
	}

	int allp = accumulate(pre.begin(),pre.end(),0ll);
	int alls = accumulate(suf.begin(),suf.end(),0ll);

	int same = v[0]-allp;

	int ans = allp + alls + abs(same);
	cout<<ans;
	cout<<"\n";
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