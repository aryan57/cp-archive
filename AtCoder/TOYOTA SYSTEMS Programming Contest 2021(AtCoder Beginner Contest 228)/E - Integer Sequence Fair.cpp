/*
	group : AtCoder - TOYOTA SYSTEMS Programming Contest 2021(AtCoder Beginner Contest 228)
	name : E - Integer Sequence Fair.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Integer_Sequence_Fair.cpp
	url : https://atcoder.jp/contests/abc228/tasks/abc228_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.11.2021 11:17:01 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 998244353;

/*
	modInverse(a) = binpow(a, phi(n)-1, n)
	If n is prime, phi(n) = n-1
	phi(n) = number of no.s from 1 to n co-prime with n
*/
int binpow(int a, int b=M-2, int m=M)
{
	assert(a>=0 && b>=0);
	a%=m;
	int res=1;
	while (b)
	{
		if(b%2)res=res*a%m;
		a=a*a%m;
		b/=2;
	}
	return res;
}

void solve()
{
	int n,k,m;
	cin>>n>>k>>m;

	if(m%M==0){
		cout<<0;
		return;
	}

	int z = binpow(k,n,M-1);
	cout<<binpow(m,z,M);
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
//	parsed : 21-November-2021 11:11:39 IST