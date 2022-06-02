/**
 *    author:  Aryan Agarwal
 *    created: 17.10.2021 16:36:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

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
	int n;
	cin>>n;

	vector <int> v(n);
	int s=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		s+=v[i];
	}

	if(spf[s]!=s){
		cout<<n<<"\n";
		for(int j=0;j<n;j++){
				cout<<j+1<<" ";
			}
		cout<<"\n";
		return;
	}

	for(int i=0;i<n;i++){
		if(spf[s-v[i]]!=s-v[i]){
			cout<<n-1<<"\n";
			for(int j=0;j<n;j++){
				if(i==j)continue;
				cout<<j+1<<" ";
			}
			cout<<"\n";
			return;
		}
	}
	for(int i=0;i<n;i++){
		if(spf[v[i]]!=v[i]){
			cout<<1<<"\n";
			cout<<i+1;
			cout<<"\n";
			return;
		}
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	sieve();
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 17-October-2021 16:35:07 IST