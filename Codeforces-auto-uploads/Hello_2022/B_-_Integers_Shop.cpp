#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
	int n;
	cin>>n;
	map<pair<int,int>,int> mp1;
	map<int,int> mp2;
	while(n--){
		int l,r,c;
		cin>>l>>r>>c;
		if(mp2[l]==0)mp2[l]=c;
		else mp2[l]=min(mp2[l],c);
		if(mp2[r]==0)mp2[r]=c;
		else mp2[r]=min(mp2[r],c);

		auto it = mp1.find({l,r});
		if(it!=mp1.end())mp1[{l,r}]=min(mp1[{l,r}],c);
		else mp1[{l,r}]=c;
		
		int ans = (mp2.begin())->second + prev(mp2.end())->second;

		it = mp1.find({(mp2.begin())->first , prev(mp2.end())->first});
		if(it!=mp1.end())ans=min(ans,it->second);
		
		cout<<ans<<"\n";
	}
}

signed main(){
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}