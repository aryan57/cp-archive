/**
 *    author:  Aryan Agarwal
 *    created: 05.05.2022 20:18:01 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	int cnt=0;

	int last1=-1;
	int first0=n;

	for(int i=0;i<n;i++){
		if(s[i]=='1')last1=max(last1,i);
		if(s[i]=='0')first0=min(first0,i);
	}

	for(int i=0;i<n;i++){
		if(last1<=i && first0>=i)cnt++;
	}

	cout<<cnt;
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