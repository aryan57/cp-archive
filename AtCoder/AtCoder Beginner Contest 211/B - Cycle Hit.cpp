/*
	group : AtCoder - AtCoder Beginner Contest 211
	name : B - Cycle Hit.cpp
	srcPath : /home/aryan/cp-gedit/B_Cycle_Hit.cpp
	url : https://atcoder.jp/contests/abc211/tasks/abc211_b
*/
#include <bits/stdc++.h>
using namespace std;
const int32_t M = 1e9 + 7;
const int32_t inf = 1e9;

#define int long long

signed main()
{
    set<string> s;
	
	for(int i=0;i<4;i++){
		string z;
		cin>>z;
		s.insert(z);
	}
 
	cout<<(((int)s.size() == 4) ? "Yes" : "No");
    return 0;
}
//	parsed : 24-July-2021 19:43:00 IST