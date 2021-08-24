/*
	group : Codeforces - Codeforces Round #740 (Div. 2, based on VK Cup 2021 - Final (Engine))
	name : A. Simply Strange Sort.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Simply_Strange_Sort.cpp
	url : https://codeforces.com/contest/1561/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 24.08.2021 20:06:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> a(n);
	for(int & x: a)cin>>x;

	int it=0;
	while(!is_sorted(a.begin(),a.end())){
		it++;

		if(it%2){
			for(int i=0;i<=n-3;i+=2){
				if(a[i]>a[i+1])swap(a[i],a[i+1]);
			}
		}else{
			for(int i=1;i<=n-2;i+=2){
				if(a[i]>a[i+1])swap(a[i],a[i+1]);
			}
		}

		// for(int x : a){
		// 	cerr<<x<<" ";
		// }
		// cerr<<"\n";

	}

	cout<<it<<"\n";
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
//	parsed : 24-August-2021 20:05:18 IST