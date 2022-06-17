/**
 *    author:  Aryan Agarwal
 *    created: 17.06.2022 08:01:13 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b;
	cin>>a>>b;
	char x='0';
	char y='1';

	if(a<b){
		swap(a,b);
		swap(x,y);
	}

	for(int c=1;c<=a;c++){
		int rem=a-c;
		if(rem>b)continue;
		string z(c,x);
		string k="";
		while (rem--)
		{
			k+=y;
			k+=x;
		}
		cout<<z+k+string(b-a+c,y);
		cout<<"\n";
		return;
	}
	assert(false);
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