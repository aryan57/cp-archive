/*
	group : Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
	name : B. Update Files.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Update_Files.cpp
	url : https://codeforces.com/contest/1606/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.10.2021 20:16:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long



void solve()
{
	int n,k;
	cin>>n>>k;

	if(n==1){
		cout<<0;
		cout<<"\n";
		return;
	}

	int pw=1;
	int p=0;

	while (true)
	{
		if(2*pw<=k){
			pw*=2;
			p++;
		}else break;
	}

	assert((1ll<<p)==pw);

	int ans=p;
	int rem=n-pw;

	if(rem>0){
		ans += 1;
		rem-=pw;
	}

	if(rem>0){
		ans += (rem+ k-1)/k;
	}

	cout<<ans;
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
//	parsed : 29-October-2021 20:09:47 IST