/*
	group : Codeforces - Codeforces Round #761 (Div. 2)
	name : B. GCD Problem.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_GCD_Problem.cpp
	url : https://codeforces.com/contest/1617/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.12.2021 19:17:47 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve()
{
	int n;
	cin>>n;

	int a,b,c;
	c=1;
	for(int x=2;x<=n-3;x++){
		a=x;
		b=n-1-x;
		if(a!=b && gcd(a,b)==1){
			cout<<a<<" "<<b<<" "<<c<<"\n";
			return;
		}
	}	
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
//	parsed : 16-December-2021 19:11:58 IST