/*
	group : Codeforces - Codeforces Round #745 (Div. 2)
	name : B. Diameter of Graph.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Diameter_of_Graph.cpp
	url : https://codeforces.com/contest/1581/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.09.2021 15:57:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;
	int z=(n*(n-1))/2;
	if(m<=n-2 || m>z){
		cout<<"NO\n";
		return;
	}

	if(n==1){
		if(m==0 && 0<k-1){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}
		return;
	}

	if(m==z){
		if(k>=3){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}

		return;
	}

	if(k>=4){
			cout<<"YES\n";
		}else{
			cout<<"NO\n";
		}



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
//	parsed : 30-September-2021 15:48:26 IST