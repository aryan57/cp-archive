/**
 *    author:  Aryan Agarwal
 *    created: 25.06.2022 17:42:08 IST
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

	vector <int> a,c;
	vector <int> temp;
	for(int i=0;i<n;i++){
		int w;
		cin>>w;
		temp.push_back(w);
		temp.push_back(w+1);
		temp.push_back(w-1);
		if(s[i]=='1')a.push_back(w);
		else c.push_back(w);
	}

	sort(a.begin(),a.end());
	sort(c.begin(),c.end());

	int ans=0;
	int s1=a.size();
	int s2=c.size();
	for(int x : temp){
		int tot=0;
		int ind = lower_bound(a.begin(),a.end(),x)-a.begin();
		tot+=s1-ind;

		ind = lower_bound(c.begin(),c.end(),x)-c.begin();
		tot+=ind;
		
		ans=max(ans,tot);
	}

	cout<<ans;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}