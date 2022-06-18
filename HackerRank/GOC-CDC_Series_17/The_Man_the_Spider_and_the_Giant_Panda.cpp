/**
 *    author:  Aryan Agarwal
 *    created: 18.06.2022 15:23:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int a,b,c;
	cin>>a;
	vector <int> v1(a);

	int cnt[3][7]={};

	for(int &x : v1){
		cin>>x;
		x%=7;
		cnt[0][x]++;
	}
	cin>>b;
	vector <int> v2(b);
	for(int &x : v2){
		cin>>x;
		x%=7;
		cnt[1][x]++;
	}
	cin>>c;
	vector <int> v3(c);
	for(int &x : v3){
		cin>>x;
		x%=7;
		cnt[2][x]++;
	}

	int ans=0;

	for(int i=0;i<7;i++){
		for(int j=0;j<7;j++){
			for(int k=0;k<7;k++){
				if((i+j+k)%7)continue;
				ans+=cnt[0][i]*cnt[1][j]*cnt[2][k];
			}
		}
	}
	cout<<ans;cout<<"\n";
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