/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:26:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn = 2e5 + 1;

void solve()
{
	int n,s;
	cin>>n>>s;
	vector <int> a(n);
	int tot=0;
	for(int i=0;i<n;i++){
		cin>>a[i];
		tot+=a[i];
	}

	if(s>tot){
		cout<<"-1\n";
		return;
	}

	vector <int> pos(tot+1,-1);
	pos[0]=0;
	int pre=0;
	int ans=n+1;
	for(int i=1;i<=n;i++){
		pre+=a[i-1];
		if(pre>=s){
			ans=min(ans,n-(i-pos[pre-s]));
		}
		if(pos[pre]==-1)pos[pre]=i;
	}
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