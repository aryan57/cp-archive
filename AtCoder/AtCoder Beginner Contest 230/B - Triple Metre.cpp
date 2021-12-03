/*
	group : AtCoder - AtCoder Beginner Contest 230
	name : B - Triple Metre.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Triple_Metre.cpp
	url : https://atcoder.jp/contests/abc230/tasks/abc230_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.12.2021 17:33:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n=s.size();
	int cnt=0;

	if(n==1){
		cout<<"Yes\n";
		return;
	}
	if(n==2){
		if(s!="oo")cout<<"Yes\n";
		else cout<<"No\n";
		return;
	}
	int st=0;
	if(s[0]=='o'){
		st=0;
	}
	else if(s[1]=='o'){
		st=1;
		cnt++;
	}
	else if(s[2]=='o'){
		st=2;
		cnt++;
	}else{
		cout<<"No\n";
		return;
	}

	int i=st;
	while (i<n)
	{
		if(s[i]!='o'){
			cout<<"No";
			return;
		}
		cnt++;
		if(i+1<n && s[i+1]!='x'){
			cout<<"No";
			return;
		}
		if(i+2<n && s[i+2]!='x'){
			cout<<"No";
			return;
		}
		i+=3;
	}

	if(cnt<=1e5)cout<<"Yes";
	else cout<<"No";
	
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
//	parsed : 03-December-2021 17:32:35 IST