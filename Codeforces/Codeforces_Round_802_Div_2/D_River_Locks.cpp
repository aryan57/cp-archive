/**
 *    author:  Aryan Agarwal
 *    created: 19.06.2022 16:21:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int cil(int x,int y){
	return (x+y-1)/y;
}

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);

	int mx=0;
	int pre=0;

	for(int i=0;i<n;i++){
		cin>>v[i];
		pre+=v[i];
		mx=max(mx,cil(pre,i+1));
	}


	int q;
	cin>>q;
	while (q--){
		int t;
		cin>>t;

		if(t<mx)cout<<"-1\n";
		else cout<<cil(pre,t)<<"\n";
	}
	
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