/**
 *    author:  Aryan Agarwal
 *    created: 07.06.2022 20:53:20 IST
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

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	vector <int> p(n);
	for(int &x : p){
		cin>>x;
		--x;
	}
	vector <bool> vis(n);
	int lcm=1;
	for(int i=0;i<n;i++){
		if(vis[i])continue;
		string z = "";
		int cur=i;
		while (!vis[cur]){
			vis[cur]=true;
			z+=s[cur];
			cur=p[cur];
		}
		int rot=0;
		string t=z;
		for(int i=1;i<=z.size();i++){
			rotate(z.begin(),z.begin()+1,z.end());
			if(z==t){
				rot=i;
				break;
			}
		}
		lcm = (lcm*rot)/gcd(lcm,rot);
	}
	cout<<lcm<<"\n";
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