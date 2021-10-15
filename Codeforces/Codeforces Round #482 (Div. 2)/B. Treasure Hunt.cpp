/*
	group : Codeforces - Codeforces Round #482 (Div. 2)
	name : B. Treasure Hunt.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Treasure_Hunt.cpp
	url : https://codeforces.com/contest/979/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 11:07:00 IST
**/
#include <bits/stdc++.h>
using namespace std;

int n;
int f(string s)
{
	unordered_map<char,int> cnt;
	int k=s.size();
	for(char x : s)
	{
		cnt[x]++;
	}
	int mx=0;
	for(char x : s)
	{
		mx=max(mx,cnt[x] + min(k-cnt[x],n));
		if(cnt[x]==k)
		{
			if(n==1)return k-1;
			else return k;
		}
	}

	return mx;
}

void solve()
{
	cin>>n;
	vector<pair<int,int> > v(3);

	for(int i=0;i<3;i++)
	{
		string s;
		cin>>s;
		v[i]={f(s),i};
	}

	sort(v.begin(),v.end());

	if(v[2].first==v[1].first){
		cout<<"Draw";
		return;
	}

	switch (v[2].second)
	{
	case 0:
		cout<<"Kuro";
		break;
	case 1:
		cout<<"Shiro";
		break;

	case 2:
		cout<<"Katie";
		break;
	
	default:
		break;
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
//	parsed : 15-October-2021 11:02:23 IST