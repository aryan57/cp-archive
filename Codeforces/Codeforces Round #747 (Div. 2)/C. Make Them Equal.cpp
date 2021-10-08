/*
	group : Codeforces - Codeforces Round #747 (Div. 2)
	name : C. Make Them Equal.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Make_Them_Equal.cpp
	url : https://codeforces.com/contest/1594/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.10.2021 21:00:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	char c;
	cin>>c;

	string s;
	cin>>s;

	bool ok = true;

	for(char x : s){
		if(x!=c){
			ok=false;
			break;
		}
	}

	if(ok){
		cout<<0;
		cout<<"\n";
		return;
	}

	for(int i=1;i<=n;i++)
	{
		ok=true;

		for(int j=i;j<=n;j+=i)
		{
			if(s[j-1]!=c){
				ok=false;
			}
		}

		if(ok){
			cout<<"1\n"<<i<<"\n";
			return;
		}
	}

	cout<<2<<"\n"<<n<<" "<<n-1<<"\n";
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
//	parsed : 08-October-2021 20:56:08 IST