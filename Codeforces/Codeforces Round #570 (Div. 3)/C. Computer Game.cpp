/*
	group : Codeforces - Codeforces Round #570 (Div. 3)
	name : C. Computer Game.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Computer_Game.cpp
	url : https://codeforces.com/contest/1183/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 19:32:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int k,n,a,b;
	cin>>k>>n>>a>>b;

	int t=k-n*b;
	if(t<=0){
		cout<<"-1\n";
		return;
	}
	int t2=a-b;
	int s=0;
	if(t%t2==0){
		s=t/t2-1;
	}else s=t/t2;
	s=min(s,n);
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
//	parsed : 02-November-2021 17:59:50 IST