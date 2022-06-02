/**
 *    author:  Aryan Agarwal
 *    created: 30.04.2022 22:18:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 4e4;
const int mxn2 = 500;
const int M = 1e9+7;

int dp[mxn+1][mxn2];
int tot=0;

void solve()
{
	int x;
	cin>>x;
	cout<<dp[x][tot-1];
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	auto is_pali = [](int x)->bool{
		string s=to_string(x);
		int n=s.size();
		int l=0,r=n-1;
		while (l<r)
		{
			if(s[l]!=s[r])return false;
			l++;
			r--;
		}
		return true;
	};

	vector <int> palindromes;
	for(int i=1;i<=mxn;i++){
		if(is_pali(i))palindromes.push_back(i);
	}

	tot=palindromes.size();
	assert(tot<=mxn2);

	for(int i=0;i<=mxn;i++){
		for(int j=0;j<tot;j++){
			if(j==0){
				dp[i][j]=1;
				continue;
			}
			dp[i][j]+=dp[i][j-1];
			dp[i][j]%=M;
			if(i>=palindromes[j])dp[i][j]+=dp[i-palindromes[j]][j];
			dp[i][j]%=M;
		}
	}

	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}