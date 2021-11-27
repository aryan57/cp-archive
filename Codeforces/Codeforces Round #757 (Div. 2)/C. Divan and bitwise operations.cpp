/*
	group : Codeforces - Codeforces Round #757 (Div. 2)
	name : C. Divan and bitwise operations.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Divan_and_bitwise_operations.cpp
	url : https://codeforces.com/contest/1614/problem/C#
*/
/**
 *    author:  Aryan Agarwal
 *    created: 27.11.2021 13:07:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int M = 1e9 + 7;

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
	int n,m;
	cin>>n>>m;
	int bit=0;
	while (m--)
	{
		int l,r,x;
		cin>>l>>r>>x;
		bit|=x;
	}

	cout<<((bit%M)*binpow(2,n-1))%M<<"\n";
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
//	parsed : 27-November-2021 13:07:49 IST