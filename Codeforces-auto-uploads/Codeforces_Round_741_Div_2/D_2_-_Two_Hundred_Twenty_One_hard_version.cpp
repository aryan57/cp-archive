/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 23:28:14 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;

	string s;
	cin>>s;

	unordered_map<int,vector<int>> mp;
	mp[0].push_back(0);
	s='#'+s;
	vector<int> pre(n+1);
	for(int i=1;i<=n;i++){
		pre[i]+=pre[i-1];
		int z=0;
		if(s[i]=='+')z++;
		else z--;
		if(i%2==0)z=-z;
		pre[i]+=z;
		mp[pre[i]+pre[i-1]].push_back(i);
	}

	while(q--){
		int l,r;
		cin>>l>>r;
		int sum=pre[r]-pre[l-1];
		if(sum==0){
			cout<<"0\n";
			continue;
		}else if(sum%2){
			cout<<1<<"\n";
		}else{
			cout<<2<<"\n"<<l<<" ";
			l++;
		}
		sum=pre[r]+pre[l-1];
		auto it = upper_bound(mp[sum].begin(),mp[sum].end(),l-1);
		assert(it!=mp[sum].end());
		cout<<*it;
		cout<<"\n";
	}
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
//	parsed : 26-August-2021 23:28:03 IST