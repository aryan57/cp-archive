/*
	group : CodeChef - CodeChef Starters 9 Division 2 (Unrated)
	name : Bus full of passengers.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Bus_full_of_passengers.cpp
	url : https://www.codechef.com/START9B/problems/BUS
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 20:07:47 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m,q;
	cin>>n>>m>>q;

	int tot=0;
	int cnt[n+1]={};
	bool ok = true;
	while(q--){
		char c;
		cin>>c;
		int x;
		cin>>x;

		if(c=='+'){cnt[x]++;tot++;}
		else {cnt[x]--;tot--;}

		if(cnt[x]<0 || tot>m){
			ok=false;
		}
	}

	cout<<(ok ? "Consistent\n" : "Inconsistent\n");
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
//	parsed : 17-August-2021 20:06:36 IST