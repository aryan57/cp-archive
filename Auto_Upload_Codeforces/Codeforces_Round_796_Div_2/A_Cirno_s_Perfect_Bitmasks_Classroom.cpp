/**
 *    author:  Aryan Agarwal
 *    created: 03.06.2022 20:08:12 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int x;
	cin>>x;
	int y=0;
	for(int bit=0;bit<=30;bit++){
		if((x>>bit)&1){
			y=(1<<bit);
			break;
		}
	}
	if(x!=y){
		cout<<y;
		cout<<"\n";
		return;
	}
	for(int bit=0;bit<=30;bit++){
		if(((x>>bit)&1)==0){
			y|=(1<<bit);
			break;
		}
	}
	cout<<y;
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