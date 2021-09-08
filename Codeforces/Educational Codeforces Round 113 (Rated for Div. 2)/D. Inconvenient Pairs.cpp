/*
	group : Codeforces - Educational Codeforces Round 113 (Rated for Div. 2)
	name : D. Inconvenient Pairs.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Inconvenient_Pairs.cpp
	url : https://codeforces.com/contest/1569/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.09.2021 21:31:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(vector<int> &y,vector<int> &v)
{
	int ans=0;
	for(int i=0;i<v.size();i++)
	{
		auto it=upper_bound(y.begin(),y.end(),v[i]);
		assert(it!=y.end());
		auto it2=lower_bound(v.begin(),v.end(),*it)-v.begin();
		it2--;
		assert(it2>=i);
		ans+=it2-i;
	}
	return ans;
}
int f2(vector<int> &y,unordered_map<int,vector<int>> &v)
{
	int ans=0;
	for(auto p : v)
	{
		sort((p.second).begin(),(p.second).end());
		for(int i=0;i<(p.second).size();i++)
		{
			auto it=upper_bound(y.begin(),y.end(),p.second[i]);
			assert(it!=y.end());
			auto it2=lower_bound((p.second).begin(),(p.second).end(),*it)-(p.second).begin();
			it2--;
			assert(it2>=i);
			ans+=it2-i;
		}
	}
	return ans;
}

void solve()
{
	int n,m,k;
	cin>>n>>m>>k;

	vector<int> x(n),y(m);
	unordered_map<int,bool> mx,my;
	for(int &z : x){cin>>z;mx[z]=true;}
	for(int &z : y){cin>>z;my[z]=true;}

	vector<int> v,h;
	unordered_map<int,vector<int>> v2,h2;

	while(k--){
		int p,q;
		cin>>p>>q;
		if(mx[p] && my[q])continue;
		if(mx[p]){
			v.push_back(q);
			v2[p].push_back(q);
		}else{
			h.push_back(p);
			h2[q].push_back(p);
		}
	}

	int ans=0;
	sort(v.begin(),v.end());
	sort(h.begin(),h.end());

	ans+=f(y,v);
	ans+=f(x,h);
	ans-=f2(y,v2);
	ans-=f2(x,h2);

	cout<<ans<<"\n";
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
//	parsed : 08-September-2021 21:29:24 IST