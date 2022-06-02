#include<bits/stdc++.h>
using namespace std;

#define int long long
const int inf = 2e18;

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	
	int dif=0;
	for(int i=1;i<n;i++){
		dif+=abs(a[i]-a[i-1]);
	}
	
	int mn=*min_element(a.begin(),a.end());
	int mx=*max_element(a.begin(),a.end());
	
	int ans=inf;
	
	
	
	ans=min(ans,dif+a[0]-1+max(x-a[n-1],0ll));
	ans=min(ans,dif+a[0]-1+2*max(x-mx,0ll));
	
	ans=min(ans,dif+2*(mn-1)+max(x-a[n-1],0ll));
	ans=min(ans,dif+2*(mn-1)+2*max(x-mx,0ll));
	ans=min(ans,dif+2*(mn-1)+max(x-a[0],0ll));
	
	
	ans=min(ans,dif+a[n-1]-1+max(x-a[0],0ll));
	ans=min(ans,dif+a[n-1]-1+2*max(x-mx,0ll));
	
	
	cout<<ans<<"\n";
}

signed main(){
	int _t=1;
	cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}
