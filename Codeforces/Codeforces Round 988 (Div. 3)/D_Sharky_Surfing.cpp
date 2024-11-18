/**
 *    author:  Aryan Agarwal
 *    created: 17.11.2024 20:42:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	using pii = pair<int,int>;
	int n,m,L;
	cin>>n>>m>>L;

	vector<pii> range(n);
	for(pii & x : range){
		cin>>x.first>>x.second;
	}

	vector<pii> power(m);
	for(pii & x : power){
		cin>>x.first>>x.second;
	}

	int ans=0;
	int cur = 1;
	int checkFrom = 0;
	priority_queue<int> pq;

	for(int i=0;i<n;i++){
		int len = range[i].second - range[i].first  + 2;

		while(checkFrom < m && power[checkFrom].first < range[i].first){
			pq.push(power[checkFrom++].second);
		}

		while (cur< len)
		{
			if(pq.empty()){
				cout<<"-1\n";
				return;
			}

			ans++;
			cur += pq.top();
			pq.pop();
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
		solve();
	}
	return 0;
}