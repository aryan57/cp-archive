/**
 *    author:  Aryan Agarwal
 *    created: 17.07.2022 17:53:10 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	vector <int> ans(n+1,-1);
	vector <int> child(n+1,-1);
	vector <int> sz(n+1,0);

	set<int> s;

	for(int i=1;i<=n;i++){
		int x;
		cin>>x;

		auto it = s.upper_bound(x);

		if(it==s.end()){
			sz[x]=1;
			s.insert(x);
		}else{
			child[x]=*it;
			sz[x]=sz[*it]+1;
			s.erase(it);
			s.insert(x);
		}

		if(sz[x]==k){
			s.erase(x);

			int cur=x;
			while (cur!=-1)
			{
				ans[cur]=i;
				cur=child[cur];
			}
		}
	}

	for(int i=1;i<=n;i++)cout<<ans[i]<<"\n";

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