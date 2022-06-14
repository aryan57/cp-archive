/*
	group : Google Coding Competitions - Round A 2021 - Kick Start 2021
	name : K-Goodness String.cpp
	srcPath : /home/aryan/cp-workspace/K_Goodness_String.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cca3
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 08:59:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;

	int l=0,r=n-1;
	int ok=0;
	while (l<r)
	{
		if(s[l]!=s[r])ok++;
		l++;
		r--;
	}

	cout<<abs(k-ok);
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
//	parsed : 20-March-2022 08:59:19 IST