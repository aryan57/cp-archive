/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 17:40:55 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;
	string s;
	cin>>s;
	string z =s + s;

	int add=0;
	while (q--)
	{
		int t,x;
		cin>>t>>x;
		if(t==1){
			add+=x;
			add%=n;
			continue;
		}

		int start=n-add;
		cout<<z[start+x-1];
		cout<<"\n";
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