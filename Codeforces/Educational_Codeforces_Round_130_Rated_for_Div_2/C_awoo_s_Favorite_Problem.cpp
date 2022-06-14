/**
 *    author:  Aryan Agarwal
 *    created: 12.06.2022 20:20:01 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s,t;
	cin>>s>>t;

	priority_queue<int,vector <int> ,greater<>>pq[3];

	for(int i=0;i<n;i++){
		pq[s[i]-'a'].push(i);
	}
	pq[0].push(n);
	pq[1].push(n);
	pq[2].push(n);

	for(int i=0;i<n;i++){
		int req = t[i]-'a';
		if(pq[req].top()!=n && min({pq[0].top(),pq[1].top(),pq[2].top()})==pq[req].top()){
			pq[req].pop();
			continue;
		}
		if(req==0){
			cout<<"NO\n";
			return;
		}
		if(req==1){
			if(pq[0].top()==n || min({pq[0].top(),pq[1].top(),pq[2].top()})!=pq[0].top()){
				cout<<"NO\n";
				return;
			}
			if(pq[1].top()==n || min({pq[1].top(),pq[2].top()})!=pq[1].top()){
				cout<<"NO\n";
				return;
			}
			pq[req].pop();
			continue;
		}
		if(req==2){
			if(pq[1].top()==n || min({pq[0].top(),pq[1].top(),pq[2].top()})!=pq[1].top()){
				cout<<"NO\n";
				return;
			}
			if(pq[2].top()==n || min({pq[0].top(),pq[2].top()})!=pq[2].top()){
				cout<<"NO\n";
				return;
			}
			pq[req].pop();
			continue;
		}
	}
	cout<<"YES\n";
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