/**
 *    author:  Aryan Agarwal
 *    created: 10.01.2022 20:09:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool f(int a,int b,int c){
	if(2*b-c>=a && (2*b-c)%a==0)return true;
	return false;
}

void solve()
{
	int a,b,c;
	cin>>a>>b>>c;
	if((a+c)>=(2*b) && ((a+c)%(2*b))==0){
		cout<<"YES\n";
		return;
	}

	if(f(a,b,c) || f(c,b,a)){
		cout<<"YES\n";
		return;
	}
	cout<<"NO\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 10-January-2022 20:07:56 IST