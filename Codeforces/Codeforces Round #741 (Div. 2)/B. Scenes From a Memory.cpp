/*
	group : Codeforces - Codeforces Round #741 (Div. 2)
	name : B. Scenes From a Memory.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Scenes_From_a_Memory.cpp
	url : https://codeforces.com/contest/1562/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 20:14:51 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

#define ARYAN_SIEVE  
const int mxn_sieve = 101;

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
	int k;
	cin>>k;
	string s;
	cin>>s;
	int cnt[10]={};
	for(char x : s){
		bool ok = false;
		if(x=='1')ok=true;
		if(x=='4')ok=true;
		if(x=='6')ok=true;
		if(x=='8')ok=true;
		if(x=='9')ok=true;

	

		cnt[x-'0']++;
		if(!ok)continue;
		cout<<"1\n"<<x<<"\n";
		return;
	}

	for(int i=0;i<k;i++){
		for(int j=i+1;j<k;j++){
			int z=10*(s[i]-'0')+s[j]-'0';
			if(spf[z]!=z){
				cout<<"2\n"<<z<<"\n";
				return;
			}
		}
	}

	assert(false);

}

signed main()
{
	sieve();
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 26-August-2021 20:09:07 IST