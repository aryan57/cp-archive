/**
 *    author:  Aryan Agarwal
 *    created: 17.06.2022 09:09:13 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> val(n),p(n);
	p[0]=-1;
	vector <int> deg(n);
	for(int i=1;i<n;i++){
		cin>>p[i];
		--p[i];
		deg[i]++;
		deg[p[i]]++;
	}
	vector <int> l(n),r(n);
	for(int i=0;i<n;i++){
		cin>>l[i]>>r[i];
	}

	queue<int> q;
	for(int i=1;i<n;i++){
		if(deg[i]==1)
		q.push(i);
	}
	int cnt=0;
	while (!q.empty())
	{
		int leaf = q.front();
		q.pop();

		if(val[leaf]>=l[leaf]){
			val[leaf]=min(val[leaf],r[leaf]);
		}else{
			val[leaf]=r[leaf];
			cnt++;
		}
		val[p[leaf]]+=val[leaf];
		deg[leaf]--;
		assert(deg[leaf]==0);
		deg[p[leaf]]--;
		if(p[leaf]!=0 && deg[p[leaf]]==1){
			q.push(p[leaf]);
		}
	}
	if(val[0]<l[0])cnt++;
	cout<<cnt;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}