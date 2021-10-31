/*
	group : Codeforces - Codeforces Round #752 (Div. 2)
	name : C. Di-visible Confusion.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Di_visible_Confusion.cpp
	url : https://codeforces.com/contest/1604/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 31.10.2021 09:09:04 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	bool yes=true;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		bool ok = false;
		for(int j=i+1;j>=2;j--){
			if(x%j){
				ok=true;
				break;
			}
		}
		yes&=ok;
	}

	if(yes)cout<<"YES\n";
	else cout<<"NO\n";
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
//	parsed : 31-October-2021 09:08:57 IST