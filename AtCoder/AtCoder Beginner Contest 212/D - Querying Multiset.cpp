/*
	group : AtCoder - AtCoder Beginner Contest 212
	name : D - Querying Multiset.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Querying_Multiset.cpp
	url : https://atcoder.jp/contests/abc212/tasks/abc212_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.08.2021 00:55:02 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int q;
	cin>>q;

	int pre=0;
	priority_queue<int> qu;
	for(int i=1;i<=q;i++)
	{
		int op;
		cin>>op;
		if(op==1){
			int x;
			cin>>x;
			qu.push(-(x-pre));
		}else if(op==2){
			int x;
			cin>>x;
			pre+=x;
		}else {
			cout<<(-qu.top())+pre<<"\n";
			qu.pop();
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
//	parsed : 03-August-2021 24:47:44 IST