/*
	group : AtCoder - AtCoder Beginner Contest 215
	name : D - Coprime 2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Coprime_2.cpp
	url : https://atcoder.jp/contests/abc215/tasks/abc215_d
*/
/**
 *    author:  Aryan Agarwal
 *    created: 21.08.2021 17:35:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ARYAN_SIEVE  
const int mxn_sieve = 1e5;

int spf[mxn_sieve + 1]; // spf -> smallest prime factor
// if spf[x]==x ,then x is prime
void sieve()
{
	spf[1] = 1;
	for (int i = 2; i <= mxn_sieve; i++)
		spf[i] = i;

	for (int i = 4; i <= mxn_sieve; i += 2)
		spf[i] = 2;

	for (int i = 3; i * i <= mxn_sieve; i++)
	{
		if (spf[i] == i)
		{
			for (int j = i * i; j <= mxn_sieve; j += i)
				if (spf[j] == j)
					spf[j] = i;
		}
	}
}

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<bool> u(m+1);
	set<int> p;
	while(n--){
		int x;
		cin>>x;
		while(x!=1){

			int z= spf[x];
			p.insert(z);
			
			while((x%z)==0){
				x/=z;
			}

		}
	}

	vector<int> vis(m+1);

	for(int t : p){
		for(int j=t;j<=m;j+=t){
			vis[j]=true;
		}
	}

	vector<int> ans;

	for(int i=1;i<=m;i++){
		if(!vis[i])ans.push_back(i);
	}

	cout<<ans.size()<<"\n";
	for(int x : ans){
		cout<<x<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;

	sieve();
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 21-August-2021 17:34:06 IST