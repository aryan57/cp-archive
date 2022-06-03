/**
 *    author:  Aryan Agarwal
 *    created: 03.06.2022 15:02:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	int q;
	cin>>q;
	vector<vector<int>> Q(q,vector<int>(3));
	for(int i=0;i<q;i++){
		cin>>Q[i][0]>>Q[i][1];
		if(Q[i][0]==1){
			Q[i][1]--;
			cin>>Q[i][2];
		}
	}
	int mx=0;
	vector<bool> vis(n);
	vector<int> ans(a);
	for(int i=q-1;i>=0;i--){
		if(Q[i][0]==1){
			int p = Q[i][1];
			int x = Q[i][2];
			if(vis[p])continue;
			vis[p]=true;
			ans[p]=max(x,mx);
		}else{
			mx=max(mx,Q[i][1]);
		}
	}
	for(int i=0;i<n;i++)if(!vis[i])ans[i]=max(ans[i],mx);
	for(int x : ans)cout<<x<<" "; 
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