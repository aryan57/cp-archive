/**
 *    author:  Aryan Agarwal
 *    created: 13.05.2022 18:32:38 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> c(n);
	for(int &x : c)cin>>x;
	vector<int> a(n);

	int tot = accumulate(c.begin(),c.end(),0ll)/n;
	int adder=0;
	vector<int> z(n);
	for(int i=n-1;i>0 && tot;i--){
		adder+=z[i];

		int t = c[i] + adder;
		t--;
		t/=i;

		assert(t<=1);
		a[i]=t;

		if(i-tot>=0)z[i-tot]++;
		adder--;

		if(t==1)tot--;
	}
	if(tot)a[0]=1;
	for(int x  : a)cout<<x<<" ";
	cout<<"\n";
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