/**
 *    author:  Aryan Agarwal
 *    created: 08.05.2022 21:45:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> p(n+1);
	for(int i=1;i<=n;i++)cin>>p[i];
	int ans=0;
	vector <int> szd(n+1);
	vector <int> szu(n+1);

	for(int a=n;a>=1;a--){

		int tot=0;

		for(int c=a+1;c<=n;c++){
			if(p[a]<p[c])ans+=tot;
			tot+=szu[c];
			if(c+1<=n)tot-=szd[c+1];
			assert(tot>=0);
		}

		for(int j=a+2;j<=n;j++){
			if(p[a]>p[j]){
				szd[j]++;
				szu[a]++;
			}
		}
	}

	cout<<ans<<"\n";
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