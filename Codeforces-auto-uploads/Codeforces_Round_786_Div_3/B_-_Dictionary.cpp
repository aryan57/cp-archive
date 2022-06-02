/**
 *    author:  Aryan Agarwal
 *    created: 02.05.2022 21:56:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	map<string,int> mp;
	int ind=0;

	for(int i=0;i<26;i++){
		for(int j=0;j<26;j++){
			if(j==i)continue;
			string z="";
			z+='a'+i;
			z+='a'+j;
			mp[z]=ind++;
		}
	}
	int q;
	cin>>q;
	while (q--)
	{
		string s;
		cin>>s;
		cout<<1+mp[s];
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