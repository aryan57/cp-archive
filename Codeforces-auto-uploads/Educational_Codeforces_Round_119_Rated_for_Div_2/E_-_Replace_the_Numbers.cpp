/**
 *    author:  Aryan Agarwal
 *    created: 02.01.2022 13:20:22 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<vector<int>> v(n,vector<int>(3));
	vector<int> ans;
	for(int i=0;i<n;i++){
		cin>>v[i][0];
		if(v[i][0]==1){
			cin>>v[i][1];
		}else{
			cin>>v[i][1]>>v[i][2];
		}
	}

	const int mxn = 5e5;
	vector<int> parent(mxn+1);
	iota(parent.begin(),parent.end(),0);

	for(int i=n-1;i>=0;i--){
		if(v[i][0]==1){
			ans.push_back(parent[v[i][1]]);
		}else{
			parent[v[i][1]]=parent[v[i][2]];
		}
	}
	reverse(ans.begin(),ans.end());
	for(int x : ans)cout<<x<<" ";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 02-January-2022 13:20:10 IST