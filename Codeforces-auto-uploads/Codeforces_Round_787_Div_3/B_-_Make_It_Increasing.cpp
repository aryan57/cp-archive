/**
 *    author:  Aryan Agarwal
 *    created: 05.05.2022 20:08:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 2e18;

void solve()
{
	int ans=inf;
	int n;
	cin>>n;

	vector <int> a(n);
	for(int &x : a)cin>>x;


	if(n==1){
		cout<<0;
		cout<<"\n";
		return;
	}

	int pre=a[n-1];
	int op=0;
	while (pre>0)
	{
		int now=pre;
		int cost=op;
		bool ok = true;
		for(int j=n-2;j>=0;j--){
			int thise=a[j];
			while (thise && thise>=now)
			{
				thise/=2;
				cost++;
			}
			if(thise>=now){
				ok=false;
				break;
			}
			now=thise;
		}

		if(ok)ans=min(ans,cost);

		pre/=2;
		op++;
	}
	if(ans==inf)ans=-1;
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