#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	string s;
	cin>>s;
	int n=s.size();
	s+='#';
	int cnt=1;
	for(int i=1;i<=n;i++){
		if(s[i]!=s[i-1]){
		
			if(cnt<2){
				cout<<"NO\n";
				return;
			}
			cnt=0;
		}
		cnt++;
	}
	cout<<"YES\n";	
}

signed main(){
	int _t=1;
	cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}
