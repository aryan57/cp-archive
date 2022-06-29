/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 10:41:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;

	int h=1;
	for(int i=0;i<n;i++){
		if(i==0){
			if(v[i])h++;
		}else{
			if(!v[i] && !v[i-1]){
				cout<<"-1\n";
				return;
			}
			if(v[i] && v[i-1]){
				h+=5;
			}
			if(v[i] && !v[i-1]){
				h+=1;
			}
		}
	}
	cout<<h<<"\n";
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