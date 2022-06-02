#include<bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;
void solve(){
	int n,m;
	cin>>m>>n;
	
	vector<vector<int>> g(m,vector<int>(n));
	for(int i=0;i<m;i++){
		for(int j=0;j<n;j++){
			cin>>g[i][j];
		}
	}
	int ans=INF;
	for(int j=0;j<n;j++){
		int k=0;
		for(int i=0;i<m;i++)k=max(k,g[i][j]);
		ans=min(ans,k);
	}
	if(n>m){
		cout<<ans<<"\n";
		return;
	}
	int z=ans;
	ans=-INF;
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=0;k<m;k++){
				ans=max(ans,min({z,g[k][i],g[k][j]}));
			}
		}
	}
	cout<<ans<<"\n";
}

signed main(){
	int t=1;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}