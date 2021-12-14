/*
	group : Codeforces - Codeforces Round #760 (Div. 3)
	name : D. Array and Operations.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Array_and_Operations.cpp
	url : https://codeforces.com/contest/1618/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.12.2021 21:06:30 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	int s=0;
	const int mx = 2e5;
	int cnt[mx+1]={};
	vector <int> v(n);
	for(int &x : v){
		cin>>x;
	}
	sort(v.begin(),v.end(),greater<>());

	for(int i=0;i<2*k;i++){
		cnt[v[i]]++;
	}
	for(int i=2*k;i<n;i++){
		// cnt[v[i]]++;
		s+=v[i];
	}

	priority_queue<int> pq;
	for(int i=1;i<=mx;i++){
		if(cnt[i])pq.push(cnt[i]);
	}

	while (!pq.empty())
	{
		
		if(pq.size()==1){
			int x=pq.top();
			pq.pop();
			s+=x/2;
		}else{
			int x1=pq.top();
			pq.pop();
			int x2=pq.top();
			pq.pop();
			if(x1-x2)pq.push(x1-x2);
		}
	}
	
	cout<<s<<"\n";
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
//	parsed : 14-December-2021 20:53:46 IST