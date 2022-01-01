/*
	group : Codeforces - Good Bye 2021: 2022 is NEAR
	name : C. Representative Edges.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Representative_Edges.cpp
	url : https://codeforces.com/contest/1616/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.12.2021 23:40:13 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	if(n<=2){
		cout<<0;
		cout<<"\n";
		return;
	}
	int mn=n;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			int cnt=0;
			for(int k=0;k<n;k++){
				int num=(k-i)*(v[j]-v[i]);
				int den=j-i;
				if(num%den){
					cnt++;
				}else{
					if(v[i] + num/den!=v[k])cnt++;
				}
			}
			mn=min(mn,cnt);
		}
	}
	cout<<mn<<"\n";
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
//	parsed : 29-December-2021 23:32:06 IST