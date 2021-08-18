/*
	group : Codeforces - Codeforces Round #739 (Div. 3)
	name : A. Dislike of Threes.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Dislike_of_Threes.cpp
	url : https://codeforces.com/contest/1560/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.08.2021 21:37:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> v;

void pre(){

	for(int i=1;;i++){

		if(i%3==0 || i%10==3)continue;

		v.push_back(i);

		if(v.size() >=1000)break;

	}

}

void solve()
{
	int n;
	cin>>n;

	cout<<v[n-1]<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	pre();

	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 18-August-2021 21:36:40 IST