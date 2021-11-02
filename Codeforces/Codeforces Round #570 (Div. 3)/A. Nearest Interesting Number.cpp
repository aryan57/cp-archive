/*
	group : Codeforces - Codeforces Round #570 (Div. 3)
	name : A. Nearest Interesting Number.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Nearest_Interesting_Number.cpp
	url : https://codeforces.com/contest/1183/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 19:20:22 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	while (true)
	{
		string t=to_string(n);
		int s=0;
		for(char x : t){
			s+=x-'0';
		}
		if(s%4==0){
			cout<<n;
			return;
		}

		n++;
		
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
//	parsed : 02-November-2021 17:59:50 IST