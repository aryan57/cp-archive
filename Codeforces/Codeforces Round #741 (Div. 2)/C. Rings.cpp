/*
	group : Codeforces - Codeforces Round #741 (Div. 2)
	name : C. Rings.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Rings.cpp
	url : https://codeforces.com/contest/1562/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 20:49:15 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ind=-1;
	bool ok = true;
	for(char x : s){
		ind++;
		if(x=='1')continue;
		ok=false;
		int l1=0;
		int r1=ind-1;
		int r2=ind;

		if(r1>=0 && r1+1>=n/2 && r2<n){
			cout<<1<<" "<<r2+1<<" "<<1<<" "<<r1+1<<"\n";
			return;
		}
		{
			int l1=ind;
			int l2=ind+1;

			if(l2<n && n-1-l2+1>=n/2){
				cout<<ind+1<<" "<<n<<" "<<ind+2<<" "<<n<<"\n";
				return;
			}
		}

	}

	assert(ok);

	cout<<1<<" "<<2*(n/2)<<" "<<1<<" "<<n/2<<"\n";
	return;
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
//	parsed : 26-August-2021 20:33:56 IST