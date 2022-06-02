/**
 *    author:  Aryan Agarwal
 *    created: 06.05.2022 20:05:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> v(n);
	int cnt=0;

	for(int &vi : v){
		cin>>vi;
		if(vi<0)cnt++;
	}

	for(int &vi : v){
		if(cnt){
			vi=-abs(vi);
			cnt--;
		}
		else vi=abs(vi);
	}

	if(is_sorted(v.begin(),v.end()))cout<<"YES\n";
	else cout<<"NO\n";
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