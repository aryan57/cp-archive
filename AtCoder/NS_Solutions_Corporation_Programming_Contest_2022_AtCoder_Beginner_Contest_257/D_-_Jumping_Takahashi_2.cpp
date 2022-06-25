/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 17:51:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> x(n),y(n),p(n);

	for(int i=0;i<n;i++){
		cin>>x[i]>>y[i]>>p[i];
	}

	int l=0;
	int inf = 1e10;
	int r=inf;
	int ans=inf;

	while (l<=r)
	{
		int m=(l+r)/2;
		bool ok = false;
		for(int i=0;i<n;i++){
			vector <bool> vis(n);
			queue<int> q;
			q.push(i);
			vis[i]=true;
			int tot=n-1;
			while (!q.empty())
			{
				int u = q.front();
				q.pop();

				for(int j=0;j<n;j++){
					if(vis[j] || (m < ((abs(x[u]-x[j])+abs(y[u]-y[j])+p[u]-1)/p[u])))continue;
					vis[j]=true;
					tot--;
					q.push(j);
				}
			}

			if(tot==0){
				ok=true;
				break;
			}
			
		}

		if(ok){
			ans=m;
			r=m-1;
		}else{
			l=m+1;
		}
	}
	cout<<ans;

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