/**
 *    author:  Aryan Agarwal
 *    created: 29.10.2021 22:15:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve()
{
	int n;
	cin>>n;
	int cnt[30]={};
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		int bit=0;

		while (x)
		{
			if(x%2)cnt[bit]++;
			x/=2;
			bit++;
		}
	}

	int g=0;
	for(int i=0;i<30;i++)g=gcd(g,cnt[i]);

	for(int i=1;i<=n;i++){
		if(g%i==0)cout<<i<<" ";
	}cout<<"\n";
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
//	parsed : 29-October-2021 22:15:15 IST