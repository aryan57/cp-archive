/**
 *    author:  Aryan Agarwal
 *    created: 23.05.2022 10:48:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int M = 1e9 + 7;
const int mxn = 400;
int fact[mxn+1];

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

int dp[mxn][mxn][mxn];

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	for(int i=0;i<n;i++)
		for(int j=0;j<n;j++)
			for(int k=0;k<n;k++)
				dp[i][j][k]=0;


	for(int l=n-1;l>=0;l--){
		for(int r=l;r<n;r++){
			if(l==r){
				dp[l][r][0]=1;
				dp[l][r][1]=1;
			}else if(l+1==r){
				dp[l][r][0]=1;
				dp[l][r][1]=2;
				dp[l][r][2]=(s[l]==s[r]?1:0);
			}else for(int k=0;k<n;k++){
				dp[l][r][k]+=dp[l][r-1][k];
				dp[l][r][k]%=M;
				dp[l][r][k]+=dp[l+1][r][k];
				dp[l][r][k]%=M;
				dp[l][r][k]-=dp[l+1][r-1][k];
				dp[l][r][k]%=M;
				dp[l][r][k]+=M;
				dp[l][r][k]%=M;
				if(s[l]==s[r] && k>=2){
					dp[l][r][k]+=dp[l+1][r-1][k-2];
					dp[l][r][k]%=M;
				}
			}
		}
	}

	int sum=0;
	for(int k=0;k<n;k++){
		int pro=1;
		pro*=fact[k];
		pro%=M;
		pro*=fact[n-k];
		pro%=M;
		pro*=dp[0][n-1][k];
		pro%=M;

		sum+=pro;
		sum%=M;
	}
	sum*=binpow(fact[n]);
	sum%=M;
	cout<<sum<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	fact[0]=1;
	for(int i=1;i<=mxn;i++){
		fact[i]=(fact[i-1]*i)%M;
	}

	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}