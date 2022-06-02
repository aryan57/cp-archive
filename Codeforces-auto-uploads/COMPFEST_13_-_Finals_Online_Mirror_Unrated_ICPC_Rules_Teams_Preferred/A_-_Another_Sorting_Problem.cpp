#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,m;
	cin>>n>>m;
	
	vector<pair<string,int>> v(n);
	
	for(int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second=i+1;
	}
	
	sort(v.begin(),v.end(),[](const pair<string,int> &a,const pair<string,int> &b) -> bool{
		int m=a.first.size();
		for(int i=0;i<m;i++){
			if(a.first[i]!=b.first[i]){
				if(i%2==0){
					return a.first[i] < b.first[i];
				}else{
					return a.first[i] > b.first[i];
				}
			}
		}
		return true;
	});
	
	for(int i=0;i<n;i++)cout<<v[i].second<<" ";
	cout<<"\n";
}

signed main(){
	
	ios_base::sync_with_stdio(false);
	cin.tie(NULL);
	int t=1;
	//cin>>t;
	while(t--){
		solve();
	}
	return 0;
}
