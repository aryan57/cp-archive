/*
	group : CodeChef - CodeChef Starters 9 Division 2 (Unrated)
	name : Fibonacci concatenation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Fibonacci_concatenation.cpp
	url : https://www.codechef.com/START9B/problems/FIBOSEQ
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 20:42:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int M = 1e9+7;
int M2 = 1e9+7 -1 ;

const int mxn = 1e5;
int f1[mxn+1];
int f2[mxn+1];

void pre(){

	f1[0]=0;
	f1[1]=1;

	f2[0]=1;
	f2[1]=1;

	for(int i=2;i<=mxn;i++){
		f1[i]=f1[i-1]+f1[i-2];
		f1[i]%=M;

		f2[i]=f2[i-1]+f2[i-2];
		f2[i]%=M2;
	}

}

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
	int n;
	cin>>n;
	int ans=1;
	ans*=f1[n];
	ans%=M;
	// cerr<<ans<<"^\n";
	int l=f2[n]-1;
	l%=M2;
	l+=M2;
	l%=M2;
	// cerr<<l<<"^\n";
	ans*=binpow(2,l,M);
	ans%=M;

	cout<<ans<<"\n";
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
//	parsed : 17-August-2021 20:40:11 IST