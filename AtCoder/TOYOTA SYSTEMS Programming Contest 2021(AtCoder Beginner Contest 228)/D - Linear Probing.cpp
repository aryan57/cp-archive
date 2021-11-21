/*
	group : AtCoder - TOYOTA SYSTEMS Programming Contest 2021(AtCoder Beginner Contest 228)
	name : D - Linear Probing.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Linear_Probing.cpp
	url : https://atcoder.jp/contests/abc228/tasks/abc228_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.11.2021 10:49:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int M = (1ll<<20);

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
	int q;
	cin>>q;
	set<int> s;
	

	int n = (1ll<<20);
	vector <int> mp(n,-1);
	for(int i=0;i<n;i++)s.insert(i);


	while (q--)
	{
		int t,x;
		cin>>t>>x;
		if(t==1){
			auto it = s.lower_bound(x%n);
			if(it==s.end()){
				it = s.lower_bound(0);
			}
			assert(it!=s.end());
			mp[*it]=x;
			s.erase(it);
		}
		else cout<<mp[x%n]<<"\n";
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
//	parsed : 21-November-2021 10:49:04 IST