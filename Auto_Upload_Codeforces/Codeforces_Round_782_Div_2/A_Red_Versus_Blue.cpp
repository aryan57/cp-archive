/**
 *    author:  Aryan Agarwal
 *    created: 14.05.2022 06:40:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,r,b;
	cin>>n>>r>>b;

	int k=r/(b+1);
	int ex = r%(b+1);
	b++;
	while(b--){
		int add=0;
		if(ex>0){
			add=1;
			ex--;
		}
		cout<<string(k+add,'R');
		if(b)cout<<'B';
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