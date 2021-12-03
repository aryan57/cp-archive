/*
	group : AtCoder - AtCoder Beginner Contest 230
	name : E - Fraction Floor Sum.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Fraction_Floor_Sum.cpp
	url : https://atcoder.jp/contests/abc230/tasks/abc230_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.12.2021 18:22:32 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int n,int i)
{
	if(i>n)return 0;

	int l=i;
	int r=n;
	int mx=i;

	while (l<=r)
	{
		int m=(l+r)/2;
		if(n/i == n/m){
			mx=max(mx,m);
			l=m+1;
		}else{
			r=m-1;
		}
	}

	assert(mx>=i && mx<=n);
	return (n/i)*(mx-i+1) + f(n,mx+1);
	 
}

 int sum( int n)
{
     int root = sqrt(n);
     int ans = 0;
 
    for (int i = 1; i <= root; i++)
        ans += n / i;
     
    ans = 2 * ans - (root * root);
    return ans;
}

void solve()
{
	int n;
	cin>>n;
	cout<<sum(n);

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
//	parsed : 03-December-2021 18:22:28 IST