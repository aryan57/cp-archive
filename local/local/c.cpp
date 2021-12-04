/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.12.2021 20:39:33 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;
	int n=s.size();
	string ans=s;
	for(int num=0;num<(1ll<<n);num++){
		string s1="",s2="";
		
		for(int bit=0;bit<n;bit++){
			if((num>>bit)&1){
				s1+=s[bit];
			}else{
				s2+=s[bit];
			}
		}
		ans=min(ans,s1+s2);
	}
	cout<<ans<<"\n";
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