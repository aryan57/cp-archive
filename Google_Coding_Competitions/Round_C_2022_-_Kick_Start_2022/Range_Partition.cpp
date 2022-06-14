/**
 *    author:  Aryan Agarwal
 *    created: 22.05.2022 16:40:24 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,x,y;
	cin>>n>>x>>y;
	int sum = (n*(n+1))/2;
	if(sum%(x+y)){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	int g=sum/(x+y);

	x*=g;
	y*=g;

	set<int> s;
	for(int i=1;i<=n;i++)s.insert(i);

	int req=x;
	vector <int> ans;
	while (req>0 && !s.empty())
	{
		auto it = s.upper_bound(req);
		if(it==s.begin())break;
		it--;
		req-=*it;
		ans.push_back(*it);
		s.erase(it);
	}

	if(req!=0){
		cout<<"IMPOSSIBLE\n";
		return;
	}
	cout<<"POSSIBLE\n";
	cout<<ans.size()<<"\n";
	for(int x : ans)cout<<x<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}