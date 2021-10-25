/*
	group : Codeforces - Codeforces Round #750 (Div. 2)
	name : F1. Korney Korneevich and XOR (easy version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F1_Korney_Korneevich_and_XOR_easy_version_.cpp
	url : https://codeforces.com/contest/1582/problem/F1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.10.2021 13:33:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> a(n);
	for(int &x : a)cin>>x;

	int mx = 512;

	vector<int> v(mx,mx+1);
	v[0]=0;
	set<int> ans;
	ans.insert(0);
	for(int i=0;i<n;i++){
		
		for(int x=0;x<mx;x++){
			if(v[a[i]^x] < a[i]){
				v[x]=min(v[x],a[i]);
				ans.insert(x);
			}
		}
	}

	cout<<ans.size()<<"\n";
	for(int x : ans)cout<<x<<" ";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 25-October-2021 13:33:04 IST