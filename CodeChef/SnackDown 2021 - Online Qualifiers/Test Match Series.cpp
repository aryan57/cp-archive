/*
	group : CodeChef - SnackDown 2021 - Online Qualifiers
	name : Test Match Series.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Test_Match_Series.cpp
	url : https://www.codechef.com/SNCKQL21/problems/TESTSERIES
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 22:32:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int c[3]={};
	
	for(int i=0;i<5;i++){
		int x;
		cin>>x;
		c[x]++;
	}

	if(c[1]>c[2])cout<<"INDIA";
	if(c[1]<c[2])cout<<"ENGLAND";
	if(c[1]==c[2])cout<<"DRAW";
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
//	parsed : 15-October-2021 22:32:35 IST