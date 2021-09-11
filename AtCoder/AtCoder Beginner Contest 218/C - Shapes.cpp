/*
	group : AtCoder - AtCoder Beginner Contest 218
	name : C - Shapes.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Shapes.cpp
	url : https://atcoder.jp/contests/abc218/tasks/abc218_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 11.09.2021 19:27:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int n;

vector <string> zero_ke_taraf_ghaskao( vector <string> &s)
{
	

	pair <int,int> p={-1,-1};
	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[i][j]!='#')continue;
			if(p.first==-1)p.first=i;
			if(p.second==-1)p.second=j;

			p.first=min(p.first,i);
			p.second=min(p.second,j);
		}
	}

	
	vector <string> ans(n,string(n,'.'));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			if(s[i][j]!='#')continue;
			ans[i-p.first][j-p.second]='#';
		}
	}

	return ans;

}

bool eq(vector <string> const &s,vector <string> const &t)
{
	for(int i=0;i<n;i++){
		if(s[i]!=t[i])return false;
	}

	return true;
}

void rot(vector <string>  &s)
{
	vector <string> ans(n,string(n,'.'));

	for(int i=0;i<n;i++)
	{
		for(int j=0;j<n;j++)
		{
			ans[j][n-1-i]=s[i][j];
		}
	}
	for(int i=0;i<n;i++)s[i]=ans[i];
	
}

void solve()
{
	cin>>n;
	vector <string> s(n),t(n);
	int c1=0;
	int c2=0;

	for(auto &z : s){cin>>z;for(char c : z)if(c=='#')c1++;}
	for(auto &z : t){cin>>z;for(char c : z)if(c=='#')c2++;}

	if(c1!=c2){
		cout<<"No";
		return;
	}

	if(c1==0){
		cout<<"Yes";
		return;
	}

	int k=4;
	t=zero_ke_taraf_ghaskao(t);
	while (k--)
	{
		if(eq(zero_ke_taraf_ghaskao(s),t)){
			cout<<"Yes\n";
			return;
		}
		rot(s);
	}

	cout<<"No";
	
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