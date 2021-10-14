/*
	group : Codeforces - Codeforces Round #748 (Div. 3)
	name : B. Make it Divisible by 25.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Make_it_Divisible_by_25.cpp
	url : https://codeforces.com/contest/1593/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.10.2021 19:54:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(string s,char x,char y)
{
	int n=s.size();
	int cnt=0;
	bool ok = false;

	for(int i=n-1;i>=0;i--)
	{
		if(y!='#')
		{
			if(s[i]==y)
			{
				y='#';
			}
			else
			{
				cnt++;
			}

		}else{
			if(s[i]==x)
			{
				x='#';
				ok=true;
				return cnt;
			}
			else
			{
				cnt++;
			}
		}
	}

	return 1e9;
}

void solve()
{
	int n;
	cin>>n;

	if(n%25==0){
		cout<<0;
		cout<<"\n";
		return;
	}

	int ans=1e9;
	string s=to_string(n);
	ans=min(ans,f(s,'0','0'));
	ans=min(ans,f(s,'7','5'));
	ans=min(ans,f(s,'2','5'));
	ans=min(ans,f(s,'5','0'));

	cout<<ans;
	cout<<"\n";
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
//	parsed : 14-October-2021 19:52:10 IST