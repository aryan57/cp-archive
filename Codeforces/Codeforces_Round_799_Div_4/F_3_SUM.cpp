/**
 *    author:  Aryan Agarwal
 *    created: 14.06.2022 20:31:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	int cnt[10]={};
	while (n--)
	{
		int x;
		cin>>x;
		cnt[x%10]++;
	}

	for(int i=0;i<10;i++){
		for(int j=0;j<10;j++){
			for(int k=0;k<10;k++){
				if((i+j+k)%10!=3)continue;

				cnt[i]--;cnt[j]--;cnt[k]--;
				if(cnt[i]>=0 && cnt[j]>=0 && cnt[k]>=0){
					cout<<"YES\n";
					return;
				}
				cnt[i]++;cnt[j]++;cnt[k]++;
			}
		}
	}
	cout<<"NO\n";
	
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