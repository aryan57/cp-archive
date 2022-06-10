/**
 *    author:  Aryan Agarwal
 *    created: 07.06.2022 20:10:34 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	if(n%3==0){
		cout<<n/3<<" "<<n/3+1<<" "<<n/3-1<<"\n";
	}
	if(n%3==1){
		cout<<n/3<<" "<<n/3+2<<" "<<n/3-1<<"\n";
	}
	if(n%3==2){
		cout<<n/3+1<<" "<<n/3+2<<" "<<n/3-1<<"\n";
	}
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