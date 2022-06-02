/**
 *    author:  Aryan Agarwal
 *    created: 02.05.2022 21:10:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 2e18;

int fun(int x,int y){
	int l=0;
	int r=max(x,y);
	int ans=inf;
	while (l<=r)
	{
		int m=(l+r)/2;
		if(max(0ll,y-m)<=min(m,2*m-x)){
			ans=min(ans,m);
			r=m-1;
		}else{
			l=m+1;
		}
	}
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n);
	for(int &x : a)cin>>x;

	int ans=inf;

	for(int i=1;i<n;i++){
		
		ans=min(ans,fun(a[i],a[i-1]));
		ans=min(ans,fun(a[i-1],a[i]));

		if(i-2>=0){
			ans=min(ans,max(a[i-2],a[i]));
			ans=min(ans,(a[i]+1)/2 + (a[i-2]+1)/2);
			ans=min(ans,(a[i])/2 + 1 + (a[i-2])/2);

		}
	}

	sort(a.begin(),a.end());

	ans=min(ans,(a[0]+1)/2 + (a[1]+1)/2);

	cout<<ans;
	cout<<"\n";
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