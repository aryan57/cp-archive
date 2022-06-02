/**
 *    author:  Aryan Agarwal
 *    created: 22.01.2022 16:30:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> k(n),h(n);
	for(int &x : k)cin>>x;
	for(int &x : h)cin>>x;
	
	vector<pair<int,int>> v(n);

	for(int i=0;i<n;i++){
		v[i]={k[i]-h[i]+1,k[i]};
	}

	sort(v.begin(),v.end());
	int tot=0;

	pair<int,int> p=v[0];

	for(int i=1;i<n;i++){
		if(v[i].first<=p.second){
			p.second=max(v[i].second,p.second);
		}else{
			tot+=((p.second-p.first+1)*(p.second-p.first+2))/2;
			p=v[i];
		}
	}
	tot+=((p.second-p.first+1)*(p.second-p.first+2))/2;

	cout<<tot<<"\n";
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
//	parsed : 22-January-2022 16:30:04 IST