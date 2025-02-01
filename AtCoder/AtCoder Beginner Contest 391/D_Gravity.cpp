/**
 *    author:  Aryan Agarwal
 *    created: 01.02.2025 18:13:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 1e18;

using pii = pair<int,int>;

void solve()
{
	int n,w;
	cin>>n>>w;

	vector<vector<pii>> v(w);

	for(int i=0;i<n;i++){
		int x,y;
		cin>>x>>y;
		--x;--y;
		v[x].push_back({y,i});
	}

	vector<stack<pii>> g(w);
	for(int j=0;j<w;j++){
		sort(v[j].rbegin(),v[j].rend());
		for(pii x : v[j]){
			g[j].push(x);
		}
	}

	vector<int> end(n,inf);

	int t=0;

	while (true){
		int mx = 0;
		for(int j=0;j<w;j++){
			if(g[j].empty()){
				mx=-1;
				break;
			}
			mx = max(mx, g[j].top().first);
		}
		if(mx==-1)break;

		t += mx + 1;

		for(int j=0;j<w;j++){
			end[g[j].top().second] = t;
			g[j].pop();

			if(!g[j].empty()){
				pii node = g[j].top();
				g[j].pop();
				node.first = max(0ll, node.first - t);
				g[j].push(node);
			}
			
		}
	}


	int q;
	cin>>q;
	while (q--){
		int t,a;
		cin>>t>>a;
		--a;
		if(t>=end[a])cout<<"No\n";
		else cout<<"Yes\n";
	}

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}