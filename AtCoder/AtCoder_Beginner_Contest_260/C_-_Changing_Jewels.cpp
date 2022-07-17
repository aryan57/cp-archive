/**
 *    author:  Aryan Agarwal
 *    created: 17.07.2022 17:41:46 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int dpR[11];
int dpB[11];
int x,y;

int fr(int);
int fb(int);

int fb(int n){
	if(n==1)return 1;
	if(dpB[n])return dpB[n];
	return dpB[n] = fr(n-1) + y*fb(n-1);
}
int fr(int n){
	if(n==1)return 0;
	if(dpR[n])return dpR[n];
	return dpR[n] = fr(n-1) + x*fb(n);
}

void solve()
{
	int n;
	cin>>n>>x>>y;

	cout<<fr(n);

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