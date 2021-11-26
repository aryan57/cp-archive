/*
	group : Codeforces - Codeforces Round #757 (Div. 2)
	name : C. Divan and bitwise operations.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Divan_and_bitwise_operations.cpp
	url : https://codeforces.com/contest/1614/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.11.2021 17:12:45 IST
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
	vector <int> v(n);
	vector<pair<pair <int,int> ,int> > z(m);
	for(int i=0;i<m;i++){
		cin>>z[i].first.first>>z[i].first.second>>z[i].second;
		z[i].first.first--;
		z[i].first.second--;
	}
	sort(z.begin(),z.end());
	int use=0;
	for(int i=0;i<m;i++){
		if(z[i].first.second<use){
			v[z[i].first.first]|=z[i].second;
			continue;
		}
		assert(use>=z[i].first.first);
		v[use]|=z[i].second;
		use=z[i].first.second+1;
	}

	int bits = 0;
    for (int i=0; i < n; ++i)
        bits |= v[i];

	bits%=M;
    int ans = bits * binpow(2, n-1);
    cout<<ans%M<<"\n";

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
//	parsed : 26-November-2021 16:55:26 IST