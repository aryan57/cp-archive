/*
	group : CodeDrills - ICPC Amritapuri 2020 Mock Round
	name : Subsegment xor sum.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Subsegment_xor_sum.cpp
	url : https://codedrills.io/contests/icpc-amritapuri-2020-mock-round/problems/subsegment-xor-sum
*/
/**
 *    author:  Aryan Agarwal
 *    created: 07.08.2021 10:34:50 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

/*
	modInverse(a) = binpow(a, phi(n)-1, n)
	If n is prime, phi(n) = n-1
	phi(n) = number of no.s from 1 to n co-prime with n
*/
int binpow(int a, int b, int m)
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

	vector<int> v(n+1);

	for(int i=1;i<=n;i++){
		cin>>v[i];
		v[i]^=v[i-1];
	}

	int M=1e9+7;
	int mxbit=31;

	int cnt[mxbit+1]={};

	for(int i=0;i<=n;i++){
		for(int bit=0;bit<=mxbit;bit++){
			if((v[i]>>bit)&1){
				cnt[bit]++;
			}
		}
	}

	int ans=0;

	int pw=1;
	for(int bit=0;bit<=mxbit;bit++){

		for(int i=0;i<=n;i++){
			int add=0;
			if((v[i]>>bit)&1){
				add = n+1- cnt[bit];
			}else {
				add = cnt[bit];
			}

			ans+=add*pw;
			ans%=M;
		}

		pw*=2;
		pw%=M;
	}

	ans*=binpow(2,M-2,M);
	ans%=M;

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
//	parsed : 07-August-2021 10:31:46 IST