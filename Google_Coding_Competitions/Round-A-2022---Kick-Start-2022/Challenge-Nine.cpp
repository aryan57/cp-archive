/*
	group : Google Coding Competitions - Round A 2022 - Kick Start 2022
	name : Challenge Nine.cpp
	srcPath : /home/aryan/cp-workspace/Challenge_Nine.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e7997
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 09:41:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n=s.size();
	int sum=0;
	for(char x : s){
		sum+=x-'0';
		sum%=9;
	}
	sum=9-sum;
	sum%=9;
	if(sum==0){
		cout<<s[0]<<"0"<<s.substr(1);
		cout<<"\n";
		return;
	}
	for(int i=0;i<n;i++){
		if(s[i]-'0'>sum){
			cout<<s.substr(0,i)<<sum<<s.substr(i)<<"\n";
			return;
		}
	}
	cout<<s<<sum;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
//	parsed : 20-March-2022 09:34:46 IST