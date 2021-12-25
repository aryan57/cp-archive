/*
	group : AtCoder - AtCoder Beginner Contest 233
	name : E - Σ[k=0..10^100]floor(X／10^k).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_k_0_10_100_floor_X_10_k_.cpp
	url : https://atcoder.jp/contests/abc233/tasks/abc233_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 25.12.2021 17:54:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	string ans="";
	int sum=0;
	for(int i=0;i<n;i++){
		sum+=s[i]-'0';
	}
	int carry=0;
	for(int i=n-1;i>=0;i--){
		ans+='0' + (carry+sum)%10;
		carry=(carry+sum)/10;
		sum-=s[i]-'0';
	}

	string z=to_string(carry);
	reverse(z.begin(),z.end());
	if(z!="0")ans+=z;
	reverse(ans.begin(),ans.end());
	cout<<ans;
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
//	parsed : 25-December-2021 17:53:15 IST