/*
	group : Codeforces - Codeforces Round #744 (Div. 3)
	name : D. Productive Meeting.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Productive_Meeting.cpp
	url : https://codeforces.com/contest/1579/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.09.2021 21:41:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	priority_queue<pair <int,int> > pq;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		pq.push({x,i+1});
	}

	vector <pair <int,int>> ans;

	while (true)
	{
		pair <int,int> p1=pq.top();
		pq.pop();
		pair <int,int> p2=pq.top();
		pq.pop();

		if(p1.first==0 || p2.first==0)break;

		ans.push_back({p1.second,p2.second});

		p1.first--;
		p2.first--;

		pq.push(p1);
		pq.push(p2);
	}

	cout<<ans.size()<<"\n";
	for(auto p : ans){
		cout<<p.first<<" "<<p.second<<"\n";
	}
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
//	parsed : 28-September-2021 21:33:08 IST