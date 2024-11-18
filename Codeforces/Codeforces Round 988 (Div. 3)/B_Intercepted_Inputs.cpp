/**
 *    author:  Aryan Agarwal
 *    created: 17.11.2024 20:09:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int k;
	cin>>k;
	vector<int> a(k);

	unordered_map<int,int> cnt;
	int pro = k-2;

	for(int i=0;i<k;i++){
		cin>>a[i];
		cnt[a[i]]++;
	}

	for(int i=0;i<k;i++){
		int m = a[i];
		if(pro%m==0){
			cnt[m]--;
			if(cnt[pro/m]){
				cout<<m<<" "<<pro/m<<"\n";
				return;
			}
			cnt[m]++;
		}
	}
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