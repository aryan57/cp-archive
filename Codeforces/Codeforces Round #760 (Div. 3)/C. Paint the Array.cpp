/*
	group : Codeforces - Codeforces Round #760 (Div. 3)
	name : C. Paint the Array.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Paint_the_Array.cpp
	url : https://codeforces.com/contest/1618/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.12.2021 20:48:49 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int gcd(int a, int b) /*__gcd doesn't work for big no.s*/
{
	if (b == 0)
		return a;
	return gcd(b, a % b);
}

void solve()
{
	int n;
	cin>>n;

	int e=0;
	int o=0;

	vector <int> v(n);
	for(int i=0;i<n;i++){
		cin>>v[i];
		if(i%2)o=gcd(o,v[i]);
		else e=gcd(e,v[i]);
	}
	bool ee=true;
	bool oo=true;
	for(int i=0;i<n;i++){
		if(i%2){
			if(v[i]%e==0)ee=false;
		}
		else{
			if(v[i]%o==0)oo=false;
		}
	}

	if(ee)cout<<e;
	else if(oo)cout<<o;
	else cout<<0;
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
//	parsed : 14-December-2021 20:46:26 IST