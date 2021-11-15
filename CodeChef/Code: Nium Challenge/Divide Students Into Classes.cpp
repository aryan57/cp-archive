/*
	group : CodeChef - Code: Nium Challenge
	name : Divide Students Into Classes.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Divide_Students_Into_Classes.cpp
	url : https://www.codechef.com/NIUM2101/problems/DIVCLASS
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.11.2021 10:45:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int nn=n;

	set<int> s;

	while (n--)
	{
		int x;
		cin>>x;
		s.insert(x);
	}

	if(nn<12){
		cout<<"no\n";
		return;
	}

	cout << ((s.size()<=12) ? "yes" : "no");
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
//	parsed : 15-November-2021 10:44:37 IST