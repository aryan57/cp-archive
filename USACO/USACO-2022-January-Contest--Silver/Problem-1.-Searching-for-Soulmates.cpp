/*
	group : USACO - USACO 2022 January Contest, Silver
	name : Problem 1. Searching for Soulmates.cpp
	srcPath : /home/aryan/Desktop/Problem_1_Searching_for_Soulmates.cpp
	url : http://www.usaco.org/index.php?page=viewproblem2&cpid=1182
*/
/**
 *    author:  Aryan Agarwal
 *    created: 10.02.2022 01:57:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b;
	cin>>a>>b;
	int ans=1e9;
	for(int s=0;(b>>s)>0 ; s++){
		int prefix=b>>s;
		int op=0;
		int current=a;

		while (current>prefix)
		{
			if(current%2){
				current++;
				op++;
			}
			current/=2;
			op++;
		}

		op+=prefix-current;

		op+=s;
		op+=__builtin_popcountll(b&((1ll<<s) -1));

		ans=min(ans,op);
	}

	cout<<ans<<"\n";
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