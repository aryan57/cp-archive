/*
	group : Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
	name : B. William the Vigilant.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_William_the_Vigilant.cpp
	url : https://codeforces.com/contest/1609/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.11.2021 20:29:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;
	string s;
	cin>>s;

	int cnt=0;

	for(int i=0;i<=n-3;i++){
		if(s.substr(i,3)=="abc")cnt++;
	}
	while (m--)
	{
		int x;
		cin>>x;
		--x;
		char c;
		cin>>c;

		if(s[x]=='a' && x<=n-3 && s.substr(x,3)=="abc")cnt--;
		if(s[x]=='b' && x<=n-2 && x-1>=0 && s.substr(x-1,3)=="abc")cnt--;
		if(s[x]=='c' && x<=n-1 && x-2>=0 && s.substr(x-2,3)=="abc")cnt--;

		s[x]=c;
		if(s[x]=='a' && x<=n-3 && s.substr(x,3)=="abc")cnt++;
		if(s[x]=='b' && x<=n-2 && x-1>=0 && s.substr(x-1,3)=="abc")cnt++;
		if(s[x]=='c' && x<=n-1 && x-2>=0 && s.substr(x-2,3)=="abc")cnt++;

		cout<<cnt<<"\n";
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
//	parsed : 28-November-2021 20:27:18 IST