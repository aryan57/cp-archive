/*
	group : AtCoder - AtCoder Beginner Contest 216
	name : E - Amusement Park.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Amusement_Park.cpp
	url : https://atcoder.jp/contests/abc216/tasks/abc216_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.08.2021 12:19:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	vector<int> v(n);
	for(int &x : v)cin>>x;

	int ans=0;
	int l=1;
	int r=*max_element(v.begin(),v.end())+1;

	while (l<=r)
	{
		int m=(l+r)/2;

		int tot=k;
		int sum=0;
		for(int x : v){
			if(m>x)continue;
			tot-=x-m+1;
			sum+=(x-m+1)*(m + x)/2;
		}
		for(int x : v){
			if(m-1>x)continue;
			if(tot<=0)break;
			tot--;
			sum+=m-1;
		}

		if(tot>=0){
			ans=max(ans,sum);
			r=m-1;
		}else{
			l=m+1;
		}
	}
	cout<<ans;
	cout<<"\n";
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
//	parsed : 30-August-2021 12:19:01 IST