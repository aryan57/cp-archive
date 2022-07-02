/**
 *    author:  Aryan Agarwal
 *    created: 02.07.2022 18:11:52 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q,x;
	cin>>n>>q>>x;

	vector <int> w(n+1),pre(n+1);
	for(int i=1;i<=n;i++){
		cin>>w[i];
		pre[i]=pre[i-1]+w[i];
	}

	vector <bool> vis(n+1);
	int i=1;
	int tot=pre[n];

	vector<pair<int,int> > order;
	int repeat=-1;
	while (true)
	{
		vis[i]=true;
		int ind = lower_bound(pre.begin()+i,pre.end(),pre[i-1]+x)-pre.begin();
		int j=-1;
		int fruits=0;
		int num=0;

		if(ind<=n){
			j=ind;
			fruits=pre[j]-pre[i-1];
			num=j-i+1;
		}else{
			int rem = x-(pre[n]-pre[i-1]);
			num=n-i+1;
			assert(rem>0);

			int full = rem/tot;
			num+=full*n;

			fruits = full*tot;
			fruits+=pre[n]-pre[i-1];

			rem%=tot;

			if(rem==0){
				j=n;
			}else{
				assert(rem>0);
				assert(fruits<x);

				int ind = lower_bound(pre.begin(),pre.end(),rem)-pre.begin();
				assert(ind<=n);
				j=ind;
				fruits+=pre[ind];
				num+=j;
			}
		}

		assert(fruits>=x);
		order.push_back({i,num});
		int next=j+1;

		if(next==n+1)next=1;
		if(vis[next]){
			repeat=next;
			break;
		}else{
			i=next;
		}
	}

	int k=order.size();
	int pos=-1;

	for(int i=0;i<k;i++){
		if(order[i].first==repeat){
			pos=i;
			break;
		}
	}

	assert(pos!=-1);

	

	while (q--)
	{
		int t;
		cin>>t;

		int start=0;
		if(t>k){
			start=0;
			int len=k-pos;
			t-=k+1;
			start+=t;
			start%=len;

			start+=pos;
		}else{
			start=t-1;
		}


		cout<<order[start].second<<"\n";
	}
	

	
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}