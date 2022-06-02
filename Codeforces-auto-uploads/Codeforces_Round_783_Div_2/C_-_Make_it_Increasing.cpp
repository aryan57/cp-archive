#include<bits/stdc++.h>
using namespace std;

#define int long long

const int inf = 2e18;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	
	int ans=inf;
	
	for(int i=0;i<n;i++){
		int z=0;
		int prev;
		
		
		prev=0;
		for(int j=i+1;j<n;j++){
			int t=(prev+1+a[j]-1)/a[j];
			z+=t;
			prev=t*a[j];
		}
		
		
		prev=0;
		for(int j=i-1;j>=0;j--){
			int t=(prev+1+a[j]-1)/a[j];
			z+=t;
			prev=t*a[j];
		}
		
		ans=min(ans,z);
	
	}
	
	cout<<ans<<"\n";
}

signed main(){
	int _t=1;
	//cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}


