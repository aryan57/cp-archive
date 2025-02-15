/**
 *    author:  Aryan Agarwal
 *    created: 15.02.2025 19:31:10 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 1e6;
vector<int> ans(mxn+1),num_multiples(mxn+1);
vector<int> cnt(mxn+1);

void solve()
{
	int n,k;
	cin>>n>>k;
	vector<int> a(n);
	

	
	for(int &x : a){
		cin>>x;
		cnt[x]++;
	}


	for(int d=1;d<=mxn;d++){
		for(int val=d;val<=mxn;val+=d){
			num_multiples[d]+=cnt[val];
		}
	}


	for(int d=1;d<=mxn;d++){
		if(num_multiples[d]<k)continue;
		for(int val=d;val<=mxn;val+=d){
			ans[val] = max(ans[val], d);
		}
	}

	for(int x : a){
		cout<<ans[x]<<"\n";
	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}