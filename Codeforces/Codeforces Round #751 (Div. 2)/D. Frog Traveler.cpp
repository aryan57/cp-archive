/*
	group : Codeforces - Codeforces Round #751 (Div. 2)
	name : D. Frog Traveler.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Frog_Traveler.cpp
	url : https://codeforces.com/contest/1602/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.10.2021 22:52:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	vector <int> a(n+1),b(n+1);
	for(int i=1;i<=n;i++)cin>>a[i];
	for(int i=1;i<=n;i++)cin>>b[i];

	queue<int> q;
	vector <pair <int,int> > par(n+1,{-1,-1});
	vector <bool> vis2(n+1);
	set<int> vis;
	for(int i=0;i<n;i++)vis.insert(i);
	par[n]={n,n};
	vis2[n]=true;
	q.push(n);

	while (!q.empty())
	{
		int u=q.front();
		q.pop();

		if(u==0){
			vector <int> ans;
			int cur=0;
			while (true)
			{
				cur=par[cur].first;
				assert(cur!=-1);
				if(cur==n)break;
				ans.push_back(par[cur].second);
			}
			reverse(ans.begin(),ans.end());
			ans.push_back(0);
			cout<<ans.size();cout<<"\n";
			for(int x : ans)cout<<x<<" ";
			cout<<"\n";
			return;
		}

		int l=u-a[u];
		int r=u;

		auto it = vis.lower_bound(l);
		vector <set<int>::iterator> temp;
		for(;it!=vis.end() && *it<=r;it++){
			temp.push_back(it);
			int v = *it + b[*it];
			if(!vis2[v]){
				par[v] = {u,*it};
				q.push(v);
				vis2[v]=true;
			}
		}

		for(auto x : temp)vis.erase(x);
	}
	
	cout<<"-1\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 29-October-2021 22:52:43 IST