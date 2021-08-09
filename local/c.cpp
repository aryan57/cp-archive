/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.08.2021 21:18:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	// string s1="abc";
	// string s2="abcd";

	string t="pqr";
	string &s1= t;
	string &s2= t;

	cout<<s1<<" "<<s2<<"\n";
	swap(s1,s2);
	cout<<s1<<" "<<s2<<"\n";
	cout<<t<<"\n";

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