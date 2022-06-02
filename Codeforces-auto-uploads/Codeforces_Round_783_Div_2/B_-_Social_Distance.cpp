#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;
	cin>>n>>m;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	sort(a.begin(),a.end(),greater<>());
	
	m-=2*a[0]+1;
	for(int i=1;i<n-1;i++){
		m-=a[i]+1;
	}
	m--;
	
	if(m>=0)cout<<"Yes\n";
	else cout<<"No\n";
}

signed main(){
	int _t=1;
	cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}


