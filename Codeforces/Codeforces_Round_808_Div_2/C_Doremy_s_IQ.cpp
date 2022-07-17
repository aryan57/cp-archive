/**
 *    author:  Aryan Agarwal
 *    created: 17.07.2022 08:39:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;

	vector <int> a(n);
	for(int &x : a)cin>>x;

	int l=0;
	int r=n-1;
	int ans=n;
	while (l<=r)
	{
		int m=(l+r)/2;

		int h=q;
		bool ok = true;
		for(int i=m;i<n;i++){
			if(h==0){
				ok=false;
				break;
			}
			if(h<a[i])h--;
		}
		if(ok){
			ans=m;
			r=m-1;
		}else{
			l=m+1;
		}
	}

	for(int i=0;i<n;i++){
		bool ok = false;
		if(i<ans){
			if(q && q>=a[i])ok=true;
		}else{
			ok=true;
		}

		cout<<(ok?'1':'0');
	}
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