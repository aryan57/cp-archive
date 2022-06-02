#include<bits/stdc++.h>
using namespace std;

#define int long long

void solve(){
	int n,x;
	cin>>n>>x;
	vector<int> a(n);
	for(int &x : a)cin>>x;
	sort(a.begin(),a.end());
	vector<int> days(n);
	int pre=0;
	for(int i=0;i<n;i++){
		pre+=a[i];
		if(x-pre<0)break;
		days[i]=(x-pre)/(i+1)+1;
	}
	int ans=0;
	int prev=0;
	for(int i=n-1;i>=0;i--){
		assert(days[i]>=prev);
		ans+=(i+1)*(days[i]-prev);
		prev=days[i];
	}
	cout<<ans<<"\n";
}

signed main(){
	int _t=1;
	cin>>_t;
	while(_t--){
		solve();
	}
	return 0;
}
