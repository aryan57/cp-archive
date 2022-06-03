/**
 *    author:  Aryan Agarwal
 *    created: 08.05.2022 20:14:28 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	int cnt=1;
	s+='#';
	int ans=0;
	for(int i=1;i<n;i++){
		if(s[i]!=s[i-1]){
			if(cnt%2){
				s[i]=s[i-1];
				ans++;
				i++;
			}
			cnt=0;
		}
		cnt++;
	}
	cout<<ans;
	cout<<"\n";
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