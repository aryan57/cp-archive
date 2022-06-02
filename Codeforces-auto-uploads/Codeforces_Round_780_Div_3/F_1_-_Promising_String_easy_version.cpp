/**
 *    author:  Aryan Agarwal
 *    created: 09.05.2022 12:51:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool ok (int sum,int tot){
	if(sum>0)return false;
	sum=abs(sum);
	if(sum%3)return false;
	// if(sum/3<=tot)return true;
	// else return false;
	return true;
}

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	int ans=0;
	for(int i=0;i<n;i++){
		int sum=0;
		int cnt=0;
		int tot=0;
		for(int j=i;j<n;j++){
			if(s[j]=='+'){
				tot+=cnt/2;
				sum++;
				cnt=0;
			}
			else {
				sum--;
				cnt++;
			}
			if(ok(sum,tot+cnt/2))ans++;
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}