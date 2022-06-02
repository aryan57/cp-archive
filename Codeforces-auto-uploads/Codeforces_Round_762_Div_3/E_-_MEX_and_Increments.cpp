#include<bits/stdc++.h>
using namespace std;

#define int long long


void solve(){
	int n;
	cin>>n;
	priority_queue<int,vector<int>,greater<>> pq_mn;
	priority_queue<int> pq_mx;
	int cnt[n+1]={};
	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		cnt[x]++;
		pq_mn.push(x);
	}
	int z=0;
	for(int i=0;i<=n;i++){
		while(!pq_mn.empty() && pq_mn.top()<i){
			pq_mx.push(pq_mn.top());
			pq_mn.pop();
		}
		if(i!=0){
			if(pq_mx.empty()){
				for(int j=i;j<=n;j++)cout<<"-1 ";
				cout<<"\n";
				return;
			}
			z+=i-1-pq_mx.top();
			pq_mx.pop();
		}
		cout<<z+cnt[i]<<" ";
	}
	cout<<"\n";
}

signed main(){
	int t;
	cin>>t;
	while(t--){
		solve();
	}
	return 0;
}