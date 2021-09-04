/*
	group : AtCoder - AtCoder Beginner Contest 217
	name : E - Sorting Queries.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Sorting_Queries.cpp
	url : https://atcoder.jp/contests/abc217/tasks/abc217_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 04.09.2021 22:34:44 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int Q;
	cin>>Q;

	priority_queue<int,vector<int>,greater<int>> pq;
	queue<int> q;

	while(Q--){
		int t;
		cin>>t;
		if(t==1){
			int x;
			cin>>x;
			q.push(x);
		}else if(t==2){
			if(!pq.empty()){
				cout<<pq.top()<<"\n";
				pq.pop();
			}else{
				assert(!q.empty());
				cout<<q.front()<<"\n";
				q.pop();
			}
		}else{
			while(!q.empty()){
				pq.push(q.front());
				q.pop();
			}
		}
	}
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
//	parsed : 04-September-2021 22:34:33 IST