/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : C. Save More Mice.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Save_More_Mice.cpp
	url : https://codeforces.com/contest/1593/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.10.2021 20:01:45 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	
	vector <int> v(k);
	for(int &x: v)cin>>x;
	sort(v.begin(),v.end());

	int cnt=0;
	int c=0;

	for(int i=k-1;i>=0;i--)
	{
		if(c>=v[i]){
			cnt+=i+1;
			break;
		}

		c+=n-v[i];
	}

	cout<<k-cnt<<"\n";
	
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
//	parsed : 14-October-2021 19:59:09 IST