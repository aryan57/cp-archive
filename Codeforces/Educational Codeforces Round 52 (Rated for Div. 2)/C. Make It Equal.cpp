/*
	group : Codeforces - Educational Codeforces Round 52 (Rated for Div. 2)
	name : C. Make It Equal.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Make_It_Equal.cpp
	url : https://codeforces.com/problemset/problem/1065/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 18:19:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	vector <int> h(n);
	for(int &x : h)cin>>x;
	sort(h.begin(),h.end());
	int mn=h[0];
	if(h[0]==h[n-1]){
		cout<<0;
		cout<<"\n";
		return;
	}

	vector <int> pre(n+1);
	for(int i=1;i<=n;i++)pre[i]=pre[i-1]+h[i-1];

	int mx = 2e5 + 1;
	int prev = mx;
	int cnt=0;
	while (true)
	{
		cnt++;

		int l=1;
		int r=prev;
		int ans=mx+1;
		while (l<=r)
		{
			int mid=(l+r)/2;

			int ind1 = lower_bound(h.begin(),h.end(),mid)-h.begin();
			int ind2 = lower_bound(h.begin(),h.end(),prev)-h.begin();

			int s1=0;
			s1+=pre[n]-pre[ind1];
			s1-=(n-ind1)*mid;
			int s2=0;
			s2+=pre[n]-pre[ind2];
			s2-=(n-ind2)*prev;

			assert(s1>=s2);

			if(s1-s2<=k){
				ans=min(ans,mid);
				r=mid-1;
			}else{
				l=mid+1;
			}
		}

		prev=ans;
		if(ans<=mn)break;
		
	}

	cout<<cnt;
	
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
//	parsed : 15-October-2021 18:19:38 IST