/*
	group : Codeforces - Codeforces Round #571 (Div. 2)
	name : D. Vus the Cossack and Numbers.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Vus_the_Cossack_and_Numbers.cpp
	url : https://codeforces.com/problemset/problem/1186/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 17:06:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<vector<int>> v(n+1,vector<int> (2));
	
	vector<int> ans(n+1);
	int sum=0;
	for(int i=1;i<=n;i++){
		double x;
		cin>>x;
		v[i][0]=(int)floor(x);
		v[i][1]=(int)ceil(x);

		ans[i]=v[i][0];
		sum+=ans[i];
	}
	for(int i=1;i<=n && sum<0;i++){

		ans[i]=v[i][1];
		sum+=v[i][1]-v[i][0];
	}

	for(int i=1;i<=n;i++){
		cout<<ans[i]<<"\n";
	}
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
//	parsed : 15-August-2021 16:58:26 IST