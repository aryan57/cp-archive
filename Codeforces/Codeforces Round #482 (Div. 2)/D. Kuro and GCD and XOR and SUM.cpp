/*
	group : Codeforces - Codeforces Round #482 (Div. 2)
	name : D. Kuro and GCD and XOR and SUM.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Kuro_and_GCD_and_XOR_and_SUM.cpp
	url : https://codeforces.com/contest/979/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 12:10:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

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
	int q;
	cin>>q;

	vector <set<int> > p(mxn_sieve+1);

	while (q--)
	{
		int t;
		cin>>t;

		if(t==1){
			int u;
			cin>>u;
			int org=u;
			while (u!=1)
			{
				int z=spf[u];
				p[z].insert(org);

				while (u%z==0)
				{
					u/=z;
				}
				
			}
			
		}else{
			int x,k,s;
			int xx,kk,ss;
			cin>>x>>k>>s;

			xx=x;
			kk=k;
			ss=s;

			int ans=0;

			while (x!=1)
			{
				int z=spf[x];
				
				int cnt=0;

				while (x%z==0)
				{
					x/=z;
					cnt++;
				}

				int cnt2=0;

				while (k%z==0)
				{
					k/=z;
					cnt2++;
				}

				if(cnt>cnt2)
				{
					
				}
				
			}

		}
	}
	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	sieve();

	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 15-October-2021 12:10:47 IST