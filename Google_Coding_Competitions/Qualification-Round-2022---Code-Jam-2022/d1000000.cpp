/*
	group : Google Coding Competitions - Qualification Round 2022 - Code Jam 2022
	name : d1000000.cpp
	srcPath : /home/aryan/cp-workspace/d1000000.cpp
	url : https://codingcompetitions.withgoogle.com/codejam/round/0000000000876ff1/0000000000a46471
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.04.2022 18:20:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> v(n);
	for(int &x : v)cin>>x;
	sort(v.begin(),v.end());
	int ans=1;
	for(int x : v)if(ans<=x)ans++;
	cout<<ans-1<<"\n";
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
//	parsed : 02-April-2022 18:20:39 IST