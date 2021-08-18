/*
	group : Codeforces - Codeforces Round #738 (Div. 2)
	name : C. Mocha and Hiking.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Mocha_and_Hiking.cpp
	url : https://codeforces.com/contest/1559/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 20:25:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<int> v(n);
	int s=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		s+=v[i];
	}

	if(s==0){
		
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}
		cout<<n+1<<" ";
		cout<<"\n";
		return;
	}

	if(v[0]==1){
		cout<<n+1<<" ";
		for(int i=1;i<=n;i++){
			cout<<i<<" ";
		}

		cout<<"\n";
		return;
	}
	cout<<1<<" ";
	for(int i=2;i<=n;i++){
		if(v[i-1]==1){
			cout<<n+1<<" ";
			for(int j=i;j<=n;j++){
				cout<<j<<" ";
			}
			cout<<"\n";
			return;
		}

		cout<<i<<" ";
	}
	assert(false);
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
//	parsed : 15-August-2021 20:16:15 IST