/*
	group : Google Coding Competitions - Round A 2022 - Kick Start 2022
	name : Speed Typing.cpp
	srcPath : /home/aryan/cp-workspace/Speed_Typing.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7021
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 09:32:06 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string i,p;
	cin>>i>>p;

	int idx=0;
	int n=i.size();
	int m=p.size();
	int del=0;
	for(int j=0;j<m;j++){
		if(idx<n && i[idx]==p[j]){
			idx++;
		}else{
			del++;
		}
	}

	if(idx!=n)cout<<"IMPOSSIBLE";
	else cout<<del;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
//	parsed : 20-March-2022 09:30:55 IST