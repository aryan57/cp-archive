/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 20:17:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	int tot=0;
	for(int &x : v){
		cin>>x;
		if(x==0)tot++;
	}

	bool zer=false;
	if(v[0]==0)zer=true;

	int z=0;
	int p=0;

	if(v[0]==0)z++;
	else p++;

	for(int i=1;i<n;i++){
		if(v[i] && zer){
			p++;
			zer=false;
		}else if(!v[i] && !zer){
			z++;
			zer=true;
		}
	}

	cout<<min({p,z+1,2ll})<<"\n";
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