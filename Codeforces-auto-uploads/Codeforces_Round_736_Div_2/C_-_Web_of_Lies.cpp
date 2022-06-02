/**
 *    author:  Aryan Agarwal
 *    created: 03.08.2021 12:26:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	int cnt[n+1]={};
	int tot=0;

	for(int i=1;i<=m;i++)
	{
		int a,b;
		cin>>a>>b;
		if(a>b)swap(a,b);

		cnt[a]++;
		if(cnt[a]==1)tot++;
	}
	int q;
	cin>>q;
	while(q--){
		int op;
		cin>>op;
		if(op==1){
			int a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			cnt[a]++;
			if(cnt[a]==1)tot++;
		}
		if(op==2){
			int a,b;
			cin>>a>>b;
			if(a>b)swap(a,b);
			cnt[a]--;
			if(cnt[a]==0)tot--;
		}
		if(op==3){
			cout<<n-tot<<"\n";
		}
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
//	parsed : 03-August-2021 12:26:29 IST