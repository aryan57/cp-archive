#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> a(n),b(n);
	for(int &x : a){
		cin>>x;
	}
	
	for(int &x : b){
		cin>>x;
	}
	
	
	
	auto fun = [](vector<int> a,vector<int> b,int n)->int{
		int ans=0;
		for(int i=1;i<n;i++){
			if(abs(a[i]-a[i-1]) + abs(b[i]-b[i-1]) > abs(b[i]-a[i-1]) + abs(a[i]-b[i-1])){
				swap(a[i],b[i]);
			}
			ans+=abs(a[i]-a[i-1]) + abs(b[i]-b[i-1]);
		}
		return ans;
	
	};
	
	int ans=fun(a,b,n);
	swap(a[0],b[0]);
	ans=min(ans,fun(a,b,n));
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


