#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
	int w,h;
	cin>>w>>h;
	int ans=0;
	for(int i=0;i<4;i++){
		int k;
		cin>>k;
		int first=-1,last=-1;
		while(k--){
			int p;
			cin>>p;
			if(first==-1)first=p;
			last=p;
		}
		int z=h;
		if(i>1)z=w;
		ans=max(ans,z*(last-first));
	}
	cout<<ans<<"\n";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}