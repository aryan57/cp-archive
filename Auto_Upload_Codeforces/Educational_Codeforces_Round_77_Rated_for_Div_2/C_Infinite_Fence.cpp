/**
 *    author:  Aryan Agarwal
 *    created: 03.06.2022 15:53:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a,int b){
	if(b==0)return a;
	return gcd(b,a%b);
}

void solve()
{
	int r,b,k;
	cin>>r>>b>>k;
	if(b<r)swap(b,r);
	int g=gcd(r,b);
	r/=g;
	b/=g;

	if(b<=1+(k-1)*r)cout<<"OBEY\n";
	else cout<<"REBEL\n";
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