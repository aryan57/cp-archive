/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/c.cpp
	url : /home/aryan/Desktop/cp-workspace/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 16:31:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int ans=0;

string f(string s)
{
	int n=s.size();

	for(int i=0;i<n-1;i++){
		if(s[i]==s[i+1]){
			s=s.substr(0,i)+s.substr(i+1,n-i-1);
			int cnt=1;
			for(int j=1;j<s.size();j++){
				if(s[j]==s[0]){
					cnt++;
				}else{
					break;
				}
			}
			ans++;
			int sz=s.size()-cnt;
			if(sz==0)return "";
			return s.substr(cnt,sz);
		}
	}

	ans+=(s.size()+1)/2;

	return "";
}

void solve()
{
	int n;
	cin>>n;

	string s;
	cin>>s;

	ans=0;
	
	while(!s.empty()){
		s=f(s);
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