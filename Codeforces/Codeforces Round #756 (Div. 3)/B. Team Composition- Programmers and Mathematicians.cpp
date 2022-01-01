/*
	group : Codeforces - Codeforces Round #756 (Div. 3)
	name : B. Team Composition: Programmers and Mathematicians.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Team_Composition_Programmers_and_Mathematicians.cpp
	url : https://codeforces.com/contest/1611/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.11.2021 20:09:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b;
	cin>>a>>b;

	int ans=0;
	int l=0;
	int r=(a+b);

	while (l<=r)
	{
		int x=(l+r)/2;
		int aa=a;
		int bb=b;

		aa-=x;
		bb-=x;

		if(aa<0 || bb<0){
			r=x-1;
			continue;
		}
		if(aa+bb>=2*x){
			l=x+1;
			ans=max(ans,x);
		}else{
			r=x-1;
		}
	}
	cout<<ans;
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
//	parsed : 25-November-2021 20:08:08 IST