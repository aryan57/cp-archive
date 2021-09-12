/*
	group : Codeforces - Codeforces Global Round 16
	name : C. MAX-MEX Cut.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_MAX_MEX_Cut.cpp
	url : https://codeforces.com/contest/1566/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 12.09.2021 20:24:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int n;
void f(int l,int r,vector<pair<int,int> > &v,int &ans)
{
	if(l>r)return;

	int t=0;
	stack<int> s;

	for(int i=l;i<=r;i++)
	{
		assert(v[i].first==v[i].second);
		if(s.empty())
		{
			s.push(v[i].first);
			if(v[i].first==0)t++;
		}else{

			if(v[i].first==s.top())
			{
				s.push(v[i].first);
				if(v[i].first==0)t++;
			}else{
				if(v[i].first==0){
					t+=2;
				}else{
					t++;
				}

				while (!s.empty())
				{
					s.pop();
				}
				
			}
		}
	}

	ans+=t;
}

void solve()
{
	
	cin>>n;

	vector<pair<int,int> > v(n+1,{0,1});
	string s1,s2;
	cin>>s1>>s2;
	for(int i=0;i<n;i++)
	{

		v[i].first = s1[i] - '0';
		v[i].second = s2[i] - '0';
	}

	int ans=0;
	int l=0;
	for(int i=0;i<=n;i++)
	{
		if(v[i].first!=v[i].second)
		{
			ans+=2;
			f(l,i-1,v,ans);
			l=i+1;
		}
		
	}

	cout<<ans-2;
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
//	parsed : 12-September-2021 20:23:50 IST