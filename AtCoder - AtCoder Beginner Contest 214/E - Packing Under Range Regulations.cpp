/*
	group : AtCoder - AtCoder Beginner Contest 214
	name : E - Packing Under Range Regulations.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Packing_Under_Range_Regulations.cpp
	url : https://atcoder.jp/contests/abc214/tasks/abc214_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.08.2021 20:44:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<pair<int,int>> v(n);
	for(int i=0;i<n;i++){
		int l,r;
		cin>>l>>r;
		v[i]={l,r};
	}

	sort(v.begin(),v.end());

	int last=-1;
	int ind=0;
	
	priority_queue<int,vector<int>,greater<int>> q;
	int lastuse=0;
	while(ind<n){

		int next=-1;
		for(int j=ind;j<n && v[j].first==last;j++){
			q.push(v[j].second);
			next=j+1;
		}

		if(next==-1){
			q.push(v[ind].second);
			next=ind+1;
			for(int j=ind+1;j<n && v[j].first==v[ind].first;j++){
				q.push(v[j].second);
				next=j+1;
			}

		}
		assert(!q.empty() && next>ind);
		if(q.top()<=lastuse){
			cout<<"No\n";
			return;
		}
		lastuse=q.top();
		q.pop();
		last=v[ind].first+1;
		ind=next;

	}

	cout<<"Yes\n";
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