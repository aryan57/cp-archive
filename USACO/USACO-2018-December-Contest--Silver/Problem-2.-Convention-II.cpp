/*
	group : USACO - USACO 2018 December Contest, Silver
	name : Problem 2. Convention II.cpp
	srcPath : /home/aryan/Desktop/Problem_2_Convention_II.cpp
	url : http://usaco.org/index.php?page=viewproblem2&cpid=859
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.02.2022 02:05:55 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

struct cow
{
	int seniority,arrival,taken;
};

struct cmp {
	bool operator()(const cow& x, const cow& y) const { return x.seniority < y.seniority; }
};

void solve()
{
	freopen("convention2.in","r",stdin);
	freopen("convention2.out","w",stdout);
	int n;
	cin>>n;
	vector<cow> v(n);
	int T=1e9;
	for(int i=0;i<n;i++){
		v[i].seniority=n-i;
		cin>>v[i].arrival>>v[i].taken;
		T=min(T,v[i].arrival);
	}
	sort(v.begin(),v.end(),[](const cow &a,const cow &b)->bool{
		return a.arrival<b.arrival;
	});
	priority_queue<cow,vector<cow>,cmp> pq;
	int ind=0;
	int ans=0;
	while (true)
	{
		while (ind<n && v[ind].arrival<=T)
		{
			pq.push(v[ind]);
			ind++;
		}
		if(pq.empty())break;
		ans=max(ans,T-pq.top().arrival);
		T+=pq.top().taken;
		pq.pop();
	}
	cout<<ans<<endl;
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
//	parsed : 15-February-2022 02:05:42 IST