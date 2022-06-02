#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
	string s;
	cin>>s;
	int cnt=0;
	for(char x : s){
		if(x=='N')cnt++;
	}
	cout<<(cnt==1?"NO":"YES")<<"\n";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}