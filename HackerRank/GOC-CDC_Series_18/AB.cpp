/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 15:19:44 IST
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
	int n;
	cin>>n;
	string s;
	cin>>s;

	int remB=count(s.begin(),s.end(),'B');
	int remQ=count(s.begin(),s.end(),'?');
	int preQ=0;
	int ans=0;
	for(int i=0;i<n;i++){
		if(s[i]=='B')remB--;
		if(s[i]=='?')remQ--;

		if(s[i]!='B'){
			int t;

			t=remB;
			t*=binpow(2,remQ+preQ);
			t%=M;
			ans+=t;
			ans%=M;

			if(remQ+preQ>=1){
				t=remQ;
				t*=binpow(2,remQ-1+preQ);
				t%=M;
				ans+=t;
				ans%=M;

			}

		}

		if(s[i]=='?')preQ++;
	}

	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}