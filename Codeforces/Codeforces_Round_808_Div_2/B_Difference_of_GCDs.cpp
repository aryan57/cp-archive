/**
 *    author:  Aryan Agarwal
 *    created: 17.07.2022 07:41:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,l,r;
	cin>>n>>l>>r;

	vector <int> a(n);

	for(int i=1;i<=n;i++){
		int lambda = r/i;
		if(lambda*i>=l && lambda*i<=r){
			a[i-1]=lambda*i;
		}else{
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
	for(int x : a){
		cout<<x<<" ";
	}
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