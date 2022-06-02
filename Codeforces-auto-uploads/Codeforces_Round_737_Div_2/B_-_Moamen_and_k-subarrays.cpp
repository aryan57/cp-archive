/**
 *    author:  Aryan Agarwal
 *    created: 09.08.2021 20:20:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	vector<int> v(n),a(n);
	unordered_map<int,int> pos;
	int cnt=0;
	for(int i=0;i<n;i++){
		cin>>v[i];
		a[i]=v[i];
		pos[a[i]]=i;
	}
	sort(a.begin(),a.end());
	int i=0;
	while(i<n){
		cnt++;
		int j=pos[a[i]];

		while(j<n && i<n){
			if(a[i]!=v[j])break;
			i++;
			j++;
		}
	}

	cout<< ((cnt<=k) ? ("Yes") : ("No"));
	cout<<"\n";
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
//	parsed : 09-August-2021 20:19:35 IST