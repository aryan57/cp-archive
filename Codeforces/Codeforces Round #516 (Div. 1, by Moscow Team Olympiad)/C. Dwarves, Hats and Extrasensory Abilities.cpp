/*
	group : Codeforces - Codeforces Round #516 (Div. 1, by Moscow Team Olympiad)
	name : C. Dwarves, Hats and Extrasensory Abilities.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Dwarves_Hats_and_Extrasensory_Abilities.cpp
	url : https://codeforces.com/problemset/problem/1063/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 19:31:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	// int n;
	// cin>>n;

	// string s;
	// int mx=1e9;

	// int org=0;
	// char c0='b';

	// cout<<"0 0"<<endl;
	// cin>>s;
	// c0=s[0];

	vector <int> v[2];
	// v[0].push_back(0);

	// for(int i=1;i<n;i++)
	// {
	// 	int m=(mx+org)/2;
	// 	cout<<m<<" "<<m<<endl;
	// 	cin>>s;

	// 	if(s[0]==c0){
	// 		v[0].push_back(m);
	// 		org=m;
	// 	}else{
	// 		v[1].push_back(m);
	// 		mx=m;
	// 	}
	// }

	v[0] = {0,500000000,562500000};
	v[1] = {750000000,625000000};

	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());

	if(!v[0].empty()){
		cout<<v[0].back()+1<<" 0 "<<v[0].back()+1<<" 1\n";
		return;
	}
	if(!v[1].empty()){
		cout<<v[1][0]-1<<" 0 "<<v[1][0]-1<<" 1\n";
		return;
	}
	
}

signed main()
{
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 15-October-2021 19:05:16 IST