/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 11:44:35 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	vector <int> pos(n);
	for(int i=0;i<n;i++){
		cin>>v[i];--v[i];
		
		if(i<n)pos[v[i]]=i;
	}

	vector <int> dup(v);
	sort(dup.begin(),dup.end());
	for(int i=1;i<n;i++){
		if(dup[i]==dup[i-1]){
			cout<<"YES\n";
			return;
		}
	}

	for(int i=0;i<=n-3;i++){
		if(v[i]==i)continue;

		int j = pos[i];
		int k = (j==n-1?n-2:n-1);

		v[j]=v[k];
		v[k]=v[i];
		v[i]=i;

		pos[v[i]]=i;
		pos[v[j]]=j;
		pos[v[k]]=k;
	}

	if(is_sorted(v.begin(),v.end()))cout<<"YES\n";
	else cout<<"NO\n";
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