/**
 *    author:  Aryan Agarwal
 *    created: 04.07.2022 21:14:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
int M = 1e9  + 7;
void solve()
{
	int n;
	cin>>n;
	vector <int> p(n);
	vector <int> pos(n);
	int l,r;
	for(int i=0;i<n;i++){
		cin>>p[i];
		if(p[i]==0){
			l=r=i;
		}
		pos[p[i]]=i;
	}

	vector <bool> vis(n);
	vis[0]=true;

	int ava=0;
	int ans=1;
	int cur=1;

	while (cur<n)
	{
		if(vis[cur]){
			ans*=ava;
			ans%=M;
			cur++;
			ava--;
			continue;

		}
		while(pos[cur]<l){
			l--;
			vis[p[l]]=true;
			ava++;
		}
		while(pos[cur]>r){
			r++;
			vis[p[r]]=true;
			ava++;
		}
		ava--;
		vis[cur]=true;
		cur++;

	}

	cout<<ans;
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