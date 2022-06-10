/**
 *    author:  Aryan Agarwal
 *    created: 03.06.2022 20:14:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int o=0,e=0;
	vector <int> v(n);
	for(int &x : v){
		cin>>x;
		if(x&1)o++;
		else e++;
	}
	if(o){
		cout<<e;
		cout<<"\n";
		return;
	}
	int mn = -1;

	for(int &x : v){
		int cnt=0;
		while ((x&1)==0)
		{
			cnt++;
			x/=2;
		}
		if(mn==-1)mn=cnt;
		else mn=min(mn,cnt);

	}
	cout<<mn+n-1<<"\n";
	
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