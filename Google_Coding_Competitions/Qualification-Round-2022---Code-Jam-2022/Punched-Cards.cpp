/*
	group : Google Coding Competitions - Qualification Round 2022 - Code Jam 2022
	name : Punched Cards.cpp
	srcPath : /home/aryan/cp-workspace/Punched_Cards.cpp
	url : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a4621b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.04.2022 18:26:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int r,c;
	cin>>r>>c;
	cout<<"\n";
	cout<<"..+";
	for(int k=1;k<=c-1;k++)cout<<"-+";
	cout<<"\n";
	cout<<"..|";
	for(int k=1;k<=c-1;k++)cout<<".|";
	cout<<"\n";

	for(int k1=1;k1<=r-1;k1++){
		for(int k=1;k<=c;k++)cout<<"+-";
		cout<<"+\n";
		for(int k=1;k<=c;k++)cout<<"|.";
		cout<<"|\n";
	}
		for(int k=1;k<=c;k++)cout<<"+-";
		cout<<"+\n";
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
//	parsed : 02-April-2022 18:26:22 IST