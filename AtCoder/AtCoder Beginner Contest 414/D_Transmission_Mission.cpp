/**
 *    author:  Aryan Agarwal
 *    created: 12.07.2025 18:36:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	map<int,int> cnt;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;
	}

	priority_queue<int,vector<int>,greater<>> gaps;

	int prev = -1;
	for(const pair <int,int> &p : cnt){
		if(prev!=-1){
			gaps.push(p.first-prev);
		}
		prev = p.first;
	}

	int sum=0;
	while (m>0 && !gaps.empty())
	{
		m--;
		sum+=gaps.top();
		gaps.pop();
	}

	cout<<sum;
	

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