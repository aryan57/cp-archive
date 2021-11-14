/*
	group : Codeforces - Codeforces Round #755 (Div. 2, based on Technocup 2022 Elimination Round 2)
	name : C. Two Arrays.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Two_Arrays.cpp
	url : https://codeforces.com/contest/1589/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.11.2021 11:54:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	priority_queue<int> a,b;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		a.push(x);
	}
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		b.push(x);
	}

	while (!a.empty() && !b.empty())
	{
		int xa = a.top();
		a.pop();
		int xb = b.top();
		b.pop();

		if(xa==xb || xa+1==xb){
			continue;
		}
		cout<<"NO\n";
		return;
		
	}

	cout<<"YES\n";
	
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
//	parsed : 14-November-2021 11:48:32 IST