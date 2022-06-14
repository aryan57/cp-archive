/**
 *    author:  Aryan Agarwal
 *    created: 22.05.2022 16:31:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool isspec(char x){
	return (x=='#' || x=='@' || x=='*' || x=='&');
}
bool isdig(char x){
	return (x>='0' && x<='9');
}
bool isdown(char x){
	return (x>='a' && x<='z');
}
bool isup(char x){
	return (x>='A' && x<='Z');
}

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	bool up=false;
	bool down=false;
	bool dig=false;
	bool spec=false;

	// int n=s.size();
	for(char x : s){
		up|=isup(x);
		down|=isdown(x);
		dig|=isdig(x);
		spec|=isspec(x);
	}

	string ans=s;
	if(!up)ans+='A';
	if(!down)ans+='a';
	if(!dig)ans+='1';
	if(!spec)ans+='&';

	while (ans.size()<7)
	{
		ans+='A';
	}

	cout<<ans;
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