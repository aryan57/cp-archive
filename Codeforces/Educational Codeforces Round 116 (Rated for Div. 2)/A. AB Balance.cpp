/*
	group : Codeforces - Educational Codeforces Round 116 (Rated for Div. 2)
	name : A. AB Balance.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_AB_Balance.cpp
	url : https://codeforces.com/contest/1606/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.10.2021 20:06:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

int n;

int ab(string s){
	int c=0;
	for(int i=0;i<n-1;i++)
		if(s[i]=='a' && s[i+1]=='b')c++;

	return c;
}
int ba(string s){
	int c=0;
	for(int i=0;i<n-1;i++)
		if(s[i]=='b' && s[i+1]=='a')c++;
	
	return c;
}


void solve()
{
	string s;
	cin>>s;

	n=s.size();

	if(ab(s)==ba(s)){
		cout<<s;
		cout<<"\n";
		return;
	}

	for(int i=0;i<n;i++){

		s[i]^='a'^'b';

		if(ab(s)==ba(s)){
			cout<<s;
			cout<<"\n";
			return;
		}

		s[i]^='a'^'b';
	}

	assert(false);
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
//	parsed : 29-October-2021 20:05:08 IST