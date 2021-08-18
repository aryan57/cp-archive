/*
	group : AtCoder - AtCoder Beginner Contest 211
	name : A - Blood Pressure.cpp
	srcPath : /home/aryan/cp-gedit/A_Blood_Pressure.cpp
	url : https://atcoder.jp/contests/abc211/tasks/abc211_a
*/
#include <bits/stdc++.h>
using namespace std;
const int32_t M = 1e9 + 7;
const int32_t inf = 1e9;

#define int long long

signed main()
{
    int a,b;
	cin>>a>>b;
	
	long double d = (1.0)*(a-b)/3 + b;
	
	cout<<d;
	
    return 0;
}
//	parsed : 24-July-2021 19:41:51 IST