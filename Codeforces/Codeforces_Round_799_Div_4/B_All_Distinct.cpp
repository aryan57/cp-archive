/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:06:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	const int mxn = 1e4;
	vector <int> cnt(mxn+1);
	while (n--)
	{
		int x;
		cin>>x;
		cnt[x]++;
	}

	int ans=0;
	int t1=0;
	for(int i=1;i<=mxn;i++){
		if(cnt[i]&1)ans++;
		else if(cnt[i]>0){
			t1++;
		}
	}
	if(t1&1)t1--;
	cout<<ans+t1;
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