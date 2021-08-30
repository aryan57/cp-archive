/*
	group : AtCoder - AtCoder Beginner Contest 216
	name : A - Signed Difficulty.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Signed_Difficulty.cpp
	url : https://atcoder.jp/contests/abc216/tasks/abc216_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.08.2021 17:30:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string z;
	cin>>z;

	string t1="";
	string t2="";

	for(int i=0;i<z.size();i++){
		if(z[i]=='.'){
			if(i+1<z.size())
			t2=z.substr(i+1,z.size()-i-1);
			break;
		}
		t1+=z[i];
	}

	int x=0;
	int y=0;

	if(!t1.empty())x=stoi(t1);
	if(!t2.empty())y=stoi(t2);

	if(y<=2){
		cout<<x<<"-";
	}else if(y<=6){

		cout<<x<<"";
	}else{
		cout<<x<<"+";
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
//	parsed : 29-August-2021 17:30:07 IST