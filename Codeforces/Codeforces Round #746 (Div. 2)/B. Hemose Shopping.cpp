/*
	group : Codeforces - Codeforces Round #746 (Div. 2)
	name : B. Hemose Shopping.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Hemose_Shopping.cpp
	url : https://codeforces.ml/contest/1592/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.10.2021 20:24:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,x;
	cin>>n>>x;

	vector <int> v(n);
	for(int &x : v)cin>>x;

	if(is_sorted(v.begin(),v.end()) || (n>=2*x)){
		cout<<"YES\n";
		return;
	}

	if(n==x){
		cout<<"NO\n";
		return;
	}

	vector <int> t;
	for(int i=n-x+1;i<=n && n-i+1>n-x;i++){
		t.push_back(v[i-1]);
	}
	sort(v.begin(),v.end());

	for(int i=n-x+1;i<=n && n-i+1>n-x;i++){
		if(v[i-1]!=t[i-(n-x+1)]){
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
//	parsed : 03-October-2021 20:24:19 IST