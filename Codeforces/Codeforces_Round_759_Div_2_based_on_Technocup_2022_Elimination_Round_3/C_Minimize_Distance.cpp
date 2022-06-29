/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 10:58:02 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

pair <int,int>  f(vector <int> &v,int k){
	int n=v.size();
	pair <int,int> ans = {0,0};
	if(n==0)return ans;

	int to_check=n-1;
	while (to_check>=0)
	{
		int last = max(to_check-(k-1),0ll);
		if(last==0){
			ans.first+=2*v[to_check];
			break;
		}
		ans.first+=2*v[to_check];
		to_check=last-1;
	}

	ans.second=ans.first-v[n-1];
	return ans;
}

void solve()
{
	int n,k;
	cin>>n>>k;
	vector <int> p,m;
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		if(x>0)p.push_back(x);
		if(x<0)m.push_back(-x);
	}

	sort(p.begin(),p.end());
	sort(m.begin(),m.end());

	pair <int,int> cnt1 = f(p,k);
	pair <int,int> cnt2 = f(m,k);

	cout<<min(cnt1.first+cnt2.second,cnt1.second+cnt2.first)<<"\n";

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