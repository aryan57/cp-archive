/*
	group : Codeforces - Codeforces Round #753 (Div. 3)
	name : E. Robot on the Board 1.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Robot_on_the_Board_1.cpp
	url : https://codeforces.com/contest/1607/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 02.11.2021 21:11:41 IST
**/
#include <bits/stdc++.h>
using namespace std;

const int INF = 2e9;

void solve()
{
	int n,m;
	cin>>n>>m;

	string s;
	cin>>s;

	pair <int,int> px={INF,-INF};
	pair <int,int> py={INF,-INF};

	pair <int,int> zxx={1,n};
	pair <int,int> zyy={1,m};

	int k=s.size();
	int x=0;
	int y=0;

	pair <int,int> ans={1,1};

	for(int i=0;i<k;i++){

		if(s[i]=='R')y++;
		if(s[i]=='L')y--;
		if(s[i]=='D')x++;
		if(s[i]=='U')x--;

		px.first=min(px.first,x);
		px.second=max(px.second,x);
		
		py.first=min(py.first,y);
		py.second=max(py.second,y);

		pair <int,int> zx={1-px.first,n-px.second};
		pair <int,int> zy={1-py.first,m-py.second};

		if(max(zx.first,zxx.first)<=min(zx.second,zxx.second) && max(zy.first,zyy.first)<=min(zy.second,zyy.second)){
			ans={max(zx.first,zxx.first),max(zy.first,zyy.first)};
		}

	}

	cout<<ans.first<<" "<<ans.second<<"\n";
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
//	parsed : 02-November-2021 21:09:13 IST