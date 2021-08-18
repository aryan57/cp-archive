/*
	group : Codeforces - Codeforces Round #739 (Div. 3)
	name : C. Infinity Table.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Infinity_Table.cpp
	url : https://codeforces.com/contest/1560/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.08.2021 22:03:26 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	if(n==1){
		cout<<"1 1\n";
		return;
	}

	int z=sqrt(n);

	for(int l=max(1ll,z-2);l<=z+1;l++){

		if(l*l < n && (l+1)*(l+1)>=n){

			int rem= n- l*l;


			if(rem<=l+1){

				int c=l+1;
				int r=rem;

				cout<<r<<" "<<c<<"\n";
				return;
			}

			rem-=(l+1);

			int c=l+1;
			int r=l+1;

			c-=rem;
			cout<<r<<" "<<c<<"\n";
				return;

		}

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
//	parsed : 18-August-2021 21:59:45 IST