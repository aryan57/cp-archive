#include<bits/stdc++.h>
using namespace std;

#define int long long
void solve(){
	int n,k;
	cin>>n>>k;
	vector<int> t;
	int i=1;
	while(k--){
		if(i>n){
			cout<<"-1\n";
			return;
		}
		t.push_back(i-1);
		i+=2;
	}
	vector<vector<char>> g(n,vector<char>(n,'.'));
	for(int x : t){
		g[x][x]='R';
	}
	for(auto v : g){
		for(char x : v)cout<<x;
		cout<<"\n";
	}
}

signed main(){
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}