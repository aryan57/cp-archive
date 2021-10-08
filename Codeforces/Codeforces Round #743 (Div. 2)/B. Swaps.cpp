/*
	group : Codeforces - Codeforces Round #743 (Div. 2)
	name : B. Swaps.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Swaps.cpp
	url : https://codeforces.com/problemset/problem/1573/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.10.2021 20:27:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> a(n),b(n);

	for(int i=0;i<n;i++){
		cin>>a[i];
	}
	for(int i=0;i<n;i++){
		cin>>b[i];
	}

	int ans=1e9;

	for(int i=0;i<n;i++){
		if(a[i]<b[0])ans=min(ans,i);
		if(a[0]<b[i])ans=min(ans,i);
	}

	cout<<ans;
	cout<<"\n";
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
//	parsed : 08-October-2021 20:27:27 IST