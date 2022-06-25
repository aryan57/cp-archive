/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 22:34:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 5e5;
const int M = 1e9 + 7;

int binpow(int a,int b=M-2,int m=M){
	a%=m;
	int res=1;
	while (b)
	{
		if(b&1)res=res*a%M;
		a=a*a%M;
		b>>=1;
	}
	return res;
}
vector <int> fact(mxn);
vector <int> invfact(mxn);

int ncr(int n,int r){
	if(r>n)return 0;
	int ans = fact[n];
	ans*=invfact[r];
	ans%=M;
	ans*=invfact[n-r];
	ans%=M;
	return ans;
}

void solve()
{
	fact[0]=1;
	invfact[0]=1;
	for(int i=1;i<mxn;i++){
		fact[i]=fact[i-1]*i%M;
		invfact[i]=invfact[i-1]*binpow(i)%M;
	}

	int n;
	cin>>n;
	int ans=0;
	for(int i=0;i<=n;i++){
		int a;
		cin>>a;
		ans+=ncr(a+i,i+1);
		ans%=M;
	}
	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}