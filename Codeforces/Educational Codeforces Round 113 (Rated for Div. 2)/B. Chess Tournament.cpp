/*
	group : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
	name : B. Chess Tournament.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Chess_Tournament.cpp
	url : https://codeforces.com/contest/1569/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.09.2021 20:33:55 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	int c2=0;

	for(char x : s)
	{
		if(x=='2')c2++;
	}

	if(c2==1 || c2==2){
		cout<<"NO\n";
		return;
	}

	s='#'+s;
	vector<vector<char>> g(n+1,vector<char>(n+1,'X'));
	vector<int> p;
	for(int i=1;i<=n;i++)
	{
		if(s[i]=='2')
		{
			p.push_back(i);
		}
		for(int j=1;j<=n;j++)
		{
			if(i==j)continue;
			g[i][j]='=';
		}
	}

	if(!p.empty())
	{
		assert(p.size()>=3);

		for(int i=0;i<p.size();i++)
		{
			g[p[i]][p[(i+1)%(p.size())]]='+';
			g[p[(i+1)%(p.size())]][p[i]]='-';
		}
	}
	cout<<"YES\n";
	for(int i=1;i<=n;i++)
	{
		for(int j=1;j<=n;j++)
		{
			cout<<g[i][j];
		}cout<<"\n";
	}

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
//	parsed : 08-September-2021 20:27:29 IST