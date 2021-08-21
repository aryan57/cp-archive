/*
	group : AtCoder - AtCoder Beginner Contest 215
	name : C - One More aab aba baa.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_One_More_aab_aba_baa.cpp
	url : https://atcoder.jp/contests/abc215/tasks/abc215_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.08.2021 17:32:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int k;
	cin>>k;

	sort(s.begin(),s.end());

	do{
		k--;
		if(k==0){
			cout<<s;
			return;
		}



	}while(next_permutation(s.begin(),s.end()));
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
//	parsed : 21-August-2021 17:31:52 IST