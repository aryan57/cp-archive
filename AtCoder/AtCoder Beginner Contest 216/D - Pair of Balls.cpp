/*
	group : AtCoder - AtCoder Beginner Contest 216
	name : D - Pair of Balls.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Pair_of_Balls.cpp
	url : https://atcoder.jp/contests/abc216/tasks/abc216_d?lang=en
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.08.2021 14:33:47 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	int cnt[n]={};
	vector <int> pos[n];
	priority_queue<pair <int,int> > q;

	vector<queue<int>> v(m);

	for(int i=0;i<m;i++){
		int k;
		cin>>k;
		for(int j=0;j<k;j++)
		{
			int x;
			cin>>x;
			x--;
			v[i].push(x);
			pos[x].push_back(i);
			if(j==0)cnt[x]++;
		}
	}

	for(int i=0;i<n;i++){
		q.push({cnt[i],i});
	}

	while(n--){
		if(q.empty()){
			cout<<"No\n";
			return;
		}
		auto p = q.top();
		q.pop();
		if(p.first!=2){
			cout<<"No\n";
			return;
		}
		int r1=pos[p.second][0];
		int r2=pos[p.second][1];

		assert(r1!=r2 && v[r1].front()==p.second && v[r2].front()==p.second);

		v[r1].pop();
		v[r2].pop();

		if(!v[r1].empty()){
			cnt[v[r1].front()]++;
			q.push({cnt[v[r1].front()],v[r1].front()});
		}
		if(!v[r2].empty()){
			cnt[v[r2].front()]++;
			q.push({cnt[v[r2].front()],v[r2].front()});
		}

	}

	cout<<"Yes";
	
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
//	parsed : 30-August-2021 14:33:40 IST