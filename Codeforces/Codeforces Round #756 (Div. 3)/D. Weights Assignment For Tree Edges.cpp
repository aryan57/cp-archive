/*
	group : Codeforces - Codeforces Round #756 (Div. 3)
	name : D. Weights Assignment For Tree Edges.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Weights_Assignment_For_Tree_Edges.cpp
	url : https://codeforces.com/contest/1611/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.11.2021 21:54:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int r=0;
	vector <int> par(n+1),p(n+1),ans(n+1,-1),w(n+1,-1);
	for(int i=1;i<=n;i++){
		cin>>par[i];
		if(par[i]==i)r=i;
	}
	int mx=0;
	for(int i=1;i<=n;i++){
		cin>>p[i];
	}
	for(int i=1;i<=n;i++){
		if(i==1){
			if(p[i]!=r)
			{
				cout<<"-1\n";
				return;
			}
			ans[r]=0;
			w[r]=0;
			continue;
		}

		if(ans[par[p[i]]]==-1){
			cout<<"-1\n";
			return;
		}

		assert(w[par[p[i]]]>=0);
		assert(mx - w[par[p[i]]] >=0);

		int req = 1 + mx - w[par[p[i]]];
		ans[p[i]]=req;
		mx++;
		w[p[i]]=mx;
	}

	for(int i=1;i<=n;i++)cout<<ans[i]<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}