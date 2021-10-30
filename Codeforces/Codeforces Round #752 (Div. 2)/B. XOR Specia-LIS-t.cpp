/*
	group : Codeforces - Codeforces Round #752 (Div. 2)
	name : B. XOR Specia-LIS-t.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_XOR_Specia_LIS_t.cpp
	url : https://codeforces.com/contest/1604/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 20:28:33 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> v(n);
	bool ok = false;
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i && v[i]<=v[i-1])ok=true;
	}

	if(n%2==0 || ok){
		cout<<"YES\n";
		return;
	}

	cout<<"NO\n";

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
//	parsed : 30-October-2021 20:11:11 IST