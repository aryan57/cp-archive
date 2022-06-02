/**
 *    author:  Aryan Agarwal
 *    created: 02.05.2022 22:02:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s,t;
	cin>>s>>t;

	if(t=="a"){
		cout<<"1\n";
		return;
	}

	int cnt=0;
	for(char c : t){
		if(c=='a'){
			cout<<"-1\n";
			return;
		}
	}

	int n=s.size();
	cout<<((1LL)<<n);
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