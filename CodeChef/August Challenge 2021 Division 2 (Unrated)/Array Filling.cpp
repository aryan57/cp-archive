/*
	group : CodeChef - August Challenge 2021 Division 2 (Unrated)
	name : Array Filling.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Array_Filling.cpp
	url : https://www.codechef.com/AUG21B/problems/ARRFILL
*/
/**
 *    author:  Aryan Agarwal
 *    created: 10.08.2021 22:10:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve()
{
	int n,m;
	cin>>n>>m;
	int sum=0;

	vector<pair<int,int>> v(m);
	for(int i=0;i<m;i++){
		cin>>v[i].first>>v[i].second;
	}
	sort(v.begin(),v.end(),greater<pair<int,int>> ());

	int cnt=n;
	int lcm=1;

	for(int i=0;i<m;i++){

		int x=v[i].first;
		int y=v[i].second;

		lcm=(lcm*y)/(gcd(lcm,y));

		int rem=n/lcm;

		assert(cnt>=rem);
		sum+=(cnt-rem)*x;

		cnt=rem;

		if(cnt==0)break;
	}

	cout<<sum<<"\n";
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
//	parsed : 10-August-2021 21:43:28 IST