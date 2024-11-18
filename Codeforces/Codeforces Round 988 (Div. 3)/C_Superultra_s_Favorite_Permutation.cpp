/**
 *    author:  Aryan Agarwal
 *    created: 17.11.2024 20:28:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	if(n<=4){
		cout<<"-1\n";
		return;
	}
	vector <int> ans;
	for(int i=2;i<=n;i+=2){
		if(i==4)continue;
		ans.push_back(i);
	}
	ans.push_back(4);
	ans.push_back(5);

	for(int i=1;i<=n;i+=2){
		if(i==5)continue;
		ans.push_back(i);
	}

	for(int x : ans)cout<<x<<" ";
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}