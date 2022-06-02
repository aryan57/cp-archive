#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	
	for(int l=a[0]-1;l<=a[0]+1;l++){
		bool ok = true;
		for(int i=0;i<n;i++){
			if(l+i<a[i]-1 || l+i>a[i]+1){
				ok=false;
				break;
			}
		}
		if(ok){
			cout<<"YES\n";
			return;
		}
	}
	cout<<"NO\n";
}

signed main(){
	int _t=1;
	cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}
