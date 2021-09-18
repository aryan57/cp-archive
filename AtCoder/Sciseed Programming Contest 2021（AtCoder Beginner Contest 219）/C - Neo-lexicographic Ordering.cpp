/*
	group : AtCoder - Sciseed Programming Contest 2021（AtCoder Beginner Contest 219）
	name : C - Neo-lexicographic Ordering.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Neo_lexicographic_Ordering.cpp
	url : https://atcoder.jp/contests/abc219/tasks/abc219_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.09.2021 17:34:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int pos[26]={};

bool comp(const string &c,const string &d)
{
	int n=c.size();
	int m=d.size();

	for(int i=0;i<min(n,m);i++)
	{
		if(c[i]!=d[i])return pos[c[i]-'a']<pos[d[i]-'a'];
	}

	if(n<m)return true;
	return false;

}

void solve()
{
	string x;
	cin>>x;

	for(int i=0;i<26;i++)
	{
		pos[x[i]-'a']=i;
	}

	int n;
	cin>>n;

	vector <string> v(n);

	for(int i=0;i<n;i++)
	{
		cin>>v[i];

		
	}

	sort(v.begin(),v.end(),comp);

	
	for(auto s : v)
	{
		cout<<s;
		cout<<"\n";
	}
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
//	parsed : 18-September-2021 17:34:04 IST