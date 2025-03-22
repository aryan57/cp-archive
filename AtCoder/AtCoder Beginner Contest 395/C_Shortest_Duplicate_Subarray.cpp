/**
 *    author:  Aryan Agarwal
 *    created: 01.03.2025 17:41:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int mn = -1;

	map<int,int> last;

	for(int i=1;i<=n;i++){
		int x;
		cin>>x;
		int pos = last[x];
		if(pos!=0){
			if(mn==-1)mn=i-pos+1;
			else mn=min(mn,i-pos+1);
		}
		last[x]=i;
	}

	cout<<mn;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}