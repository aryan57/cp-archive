/**
 *    author:  Aryan Agarwal
 *    created: 30.04.2022 23:28:24 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

const int M = 1e9+7;

void solve()
{
	int b,q,y;
	cin>>b>>q>>y;
	int c,r,z;
	cin>>c>>r>>z;

	if(r%q){
		cout<<0;
		cout<<"\n";return;
	}
	int r1=b+q*(y-1);
	int r2=c+r*(z-1);
	int l1=b;
	int l2=c;

	if(r1<r2 || l1>l2 || (l2-l1)%q){
		cout<<"0\n";
		return;
	}
	if(l1>l2-r || r1<r2+r){
		cout<<"-1\n";
		return;
	}

	int L=l2-r+1;
	int R=r2+r-1;

	int ans=0;

	for(int i=1;i*i<=r;i++){
		
		if(((i*q)/gcd(i,q))==r){
			int k = (r-1)/i;
			ans+=(k+1)*(k+1);
			ans%=M;
		}
		if(i*i!=r){
			if((((r/i)*q)/gcd((r/i),q))!=r)continue;
			int k = (r-1)/(r/i);
			ans+=(k+1)*(k+1);
			ans%=M;
		}
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