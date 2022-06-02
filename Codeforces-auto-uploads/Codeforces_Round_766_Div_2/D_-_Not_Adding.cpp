#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn = 1e6;

int gcd(int a,int b){
	return b==0?a:gcd(b,a%b);
}

void solve(){
	int n;
	cin>>n;
	vector<bool> pre(mxn+1);
	int ans=0;
	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		pre[x]=true;
	}
	
	for(int i=mxn;i>=1;i--){
		int g=0;
		for(int j=i;j<=mxn;j+=i){
			if(pre[j]){
				g=gcd(j/i,g);
			}
		}
		if(!pre[i] && g==1){
			ans++;
			pre[i]=true;
		}
	}
	cout<<ans<<"\n";
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
