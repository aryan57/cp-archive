/*
	group : CodeChef - AlgoManiac - Code For Future Division 1 (Unrated)
	name : The Old Saint And Three Questions.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/The_Old_Saint_And_Three_Questions.cpp
	url : https://www.codechef.com/CDMN21A/problems/THREEQ
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.09.2021 10:08:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n=3;
	vector<int> a(n),b(n);

	for(int &x : a)cin>>x;
	for(int &x : b)cin>>x;

	cout<< (accumulate(a.begin(),a.end(),0)==accumulate(b.begin(),b.end(),0)?"Pass\n":"Fail\n");
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
//	parsed : 03-September-2021 10:07:39 IST