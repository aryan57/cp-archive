/**
 *    author:  Aryan Agarwal
 *    created: 06.05.2022 20:23:36 IST
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
	vector <int> a(n),b(n),d(n);

	for(int &x : a)cin>>x;
	for(int &x : b)cin>>x;
	for(int &x : d)cin>>x;

	vector <int> posa(n+1),posb(n+1);

	for(int i=0;i<n;i++){
		posa[a[i]]=i;
		posb[b[i]]=i;
	}

	int cnt=0;
	vector <bool> visited(n);
	for(int i=0;i<n;i++){
		if(visited[i] || a[i]==b[i] || d[i]==0)continue;

		int num=d[i];

		int pos=i;
		while (!visited[pos])
		{
			visited[pos]=true;
			if(num==a[pos]){
				pos=posa[b[pos]];
				num=a[pos];
			}else{
				pos=posb[a[pos]];
				num=b[pos];
			}
		}
		
	}

	for(int i=0;i<n;i++){
		if(visited[i] || a[i]==b[i])continue;

		int num=d[i];
		if(d[i]==0){
			num=a[i];
			cnt++;
		}

		int pos=i;
		while (!visited[pos])
		{
			visited[pos]=true;
			if(num==a[pos]){
				pos=posa[b[pos]];
				num=a[pos];
			}else{
				pos=posb[a[pos]];
				num=b[pos];
			}
		}
		
	}

	cout<<binpow(2,cnt)<<"\n";
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