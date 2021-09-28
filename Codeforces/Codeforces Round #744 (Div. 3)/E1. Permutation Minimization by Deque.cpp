/*
	group : Codeforces - Codeforces Round #744 (Div. 3)
	name : E1. Permutation Minimization by Deque.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E1_Permutation_Minimization_by_Deque.cpp
	url : https://codeforces.com/contest/1579/problem/E1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.09.2021 21:07:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	deque<int> d;

	int x;
	cin>>x;
	d.push_back(x);

	for(int i=1;i<n;i++){
		cin>>x;
		if(d.front()>x){
			d.push_front(x);
		}else{
			d.push_back(x);
		}
	}

	while (!d.empty())
	{
		cout<<d.front()<<" ";
		d.pop_front();
	}

	cout<<"\n";
	
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
//	parsed : 28-September-2021 21:07:38 IST