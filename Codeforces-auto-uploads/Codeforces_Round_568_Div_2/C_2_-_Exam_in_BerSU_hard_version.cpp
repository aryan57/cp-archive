/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 14:22:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	int cnt[101]={};
	int tot=0;
	while(n--){

		int t;
		cin>>t;
		int rem=tot;
		int ans=0;
		for(int i=100;i>=1 && rem > m-t;i--){
			if(rem-i*cnt[i]>m-t){
				rem-=i*cnt[i];
				ans+=cnt[i];
			}else{
				int k = (rem + t-m+i-1)/i;
				assert(k<=cnt[i]);
				rem-=i*k;
				ans+=k;
				break;
			}
		}

		cout<<ans<<" ";

		cnt[t]++;
		tot+=t;

	}
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 15-August-2021 14:17:29 IST