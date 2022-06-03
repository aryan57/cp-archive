/**
 *    author:  Aryan Agarwal
 *    created: 14.05.2022 15:27:06 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;
	int sum=0;
	vector<int> a(n);
	for(int &x : a){
		cin>>x;
		sum+=x;
	}
	vector<int> prev(n);
	int last=-1;
	int lasti=-1;
	int time=0;
	while(q--){
		time++;
		int t;
		cin>>t;
		if(t==1){
			int i,x;
			cin>>i>>x;--i;
			int prevval=a[i];
			if(lasti>prev[i])prevval=last;

			sum-=prevval;
			a[i]=x;
			sum+=x;

			prev[i]=time;
		}else{
			int x;
			cin>>x;

			sum=0;
			sum+=n*x;

			lasti=time;
			last=x;
		}

		cout<<sum<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	//cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}