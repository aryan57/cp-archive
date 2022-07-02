/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 17:45:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int INF = 2e18;

void solve()
{
	int n,x;
	cin>>n>>x;

	int prev=0;
	int a,b;

	cin>>a>>b;
	int mn = b;
	int ans = a + b*(x);
	prev=a+b;
	for(int i=1;i<n;i++){
		cin>>a>>b;
		prev+=a+b;
		mn=min(mn,b);
		if(i+1<=x){
			ans=min(ans,prev+mn*(x-i-1));
		}
	}
	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}