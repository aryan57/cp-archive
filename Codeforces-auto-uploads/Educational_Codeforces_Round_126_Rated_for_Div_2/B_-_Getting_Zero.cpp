#include<bits/stdc++.h>
using namespace std;

#define int long long

const int mxn = 32768;
const int inf = 2e18;

void solve(){
	int n;
	cin>>n;
	vector<int> a(n);
	for(int &x : a){
		cin>>x;
	}
	
	vector<int> dp(mxn+1,inf);
	dp[0]=dp[mxn]=0;
	
	
	
	int kk=20;
	
	while(kk--){
		int mn = mxn;
		for(int i=mxn-1;i>0;i--){
			dp[i]=min(dp[i],mxn-i);
			
			int to = (2*i)%mxn;
			dp[i]=min(dp[i],1+dp[to]);
			
			dp[i] = min(dp[i],mn-i);
			
			mn=min(mn,i+dp[i]);
			
		}
	}
	
	
	
	
	for(int x : a){
		cout<<dp[x]<<" ";
	}
	
}

signed main(){
	int _t=1;
	//cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}


