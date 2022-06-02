#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;
	cin>>n>>m;
	if(n==m){
		cout<<n+m-2<<"\n";
		return;
	}
	if(n<m)swap(n,m);
	if(m==1){
		if(n==2)cout<<1<<"\n";
		else cout<<"-1\n";
		return;
	}
	
	int ans=2*m-2+2*(n-m)-1;
	if(n%2==m%2)ans++;
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


