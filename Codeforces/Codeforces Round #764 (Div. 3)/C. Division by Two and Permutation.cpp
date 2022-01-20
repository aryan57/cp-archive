/*
	group : Codeforces - Codeforces Round #764 (Div. 3)
	name : C. Division by Two and Permutation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Division_by_Two_and_Permutation.cpp
	url : https://codeforces.com/contest/1624/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 10.01.2022 20:17:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector< vector<bool> > v(n+1,vector <bool> (n+1));
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		while(x!=1){
			if(x<=n)
			v[x][i]=true;
			x/=2;
		}
		v[1][i]=true;
	}
	vector <bool> use(n+1);
	for(int i=n;i>=1;i--){
		bool ok = false;
		for(int j=1;j<=n;j++){
			if(use[j])continue;
			if(v[i][j]){
				use[j]=true;
				ok=true;
				break;
			}
		}
		if(!ok){
			cout<<"NO\n";
			return;
		}
	}
	cout<<"YES\n";
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
//	parsed : 10-January-2022 20:12:51 IST