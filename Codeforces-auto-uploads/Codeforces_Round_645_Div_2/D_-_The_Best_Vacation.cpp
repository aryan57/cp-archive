#include<bits/stdc++.h>
using namespace std;

#define int long long

signed main(){
	int n,x;
	cin>>n>>x;
	vector<int> pre(2*n+1);
	vector<int> pre2(2*n+1);
	vector<int> v(n+1);
	for(int i=1;i<=n;i++){
		cin>>v[i];
		pre[i]+=pre[i-1]+v[i];
		pre2[i]+=pre2[i-1]+v[i]*(v[i]+1)/2;
	}
	for(int i=n+1;i<=2*n;i++){
		pre[i]+=pre[i-1]+v[i-n];
		pre2[i]+=pre2[i-1]+v[i-n]*(v[i-n]+1)/2;
	}

	int ans=0;
	
	for(int i=n+1;i<=2*n;i++){
		int j = upper_bound(pre.begin(),pre.end(),pre[i]-x)-pre.begin();
		assert(j>=2 && j<=i);
		int extra_len=pre[i]-pre[j-1]-x;
		int sum=pre2[i]-pre2[j-1]-(extra_len*(extra_len+1)/2);
		ans=max(ans,sum);
	}
	cout<<ans;
	return 0;
	
}