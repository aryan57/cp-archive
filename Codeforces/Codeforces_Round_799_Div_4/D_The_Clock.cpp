/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:18:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int time(string s){
	return stoi(s.substr(0,2))*60 + stoi(s.substr(3,2));
}

bool ok(int t){
	string z(2,'0');
	z+=to_string(t/60);
	
	string z1(2,'0');
	z1+=to_string(t%60);

	z=z.substr(z.size()-2,2);
	z1=z1.substr(z1.size()-2,2);

	return (z[0]==z1[1] && z[1]==z1[0]);
}

void solve()
{
	string s;
	cin>>s;
	int x;
	cin>>x;
	const int mxn = 1440;
	vector <bool> vis(mxn);
	int t = time(s);
	int cnt=0;
	while (!vis[t])
	{
		vis[t]=true;
		if(ok(t))cnt++;
		t+=x;
		t%=mxn;
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