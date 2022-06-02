/**
 *    author:  Aryan Agarwal
 *    created: 30.12.2021 00:14:29 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int i,int n,vector <int> &v,int x){
	if(i>=n)return 0;
	set<int> s;
	s.insert(0);
	int pre=0;
	pre+=v[i];
	int t=pre-x*(1);
	int toadd=t;
	for(int j=i+1;j<n;j++){
		pre+=v[j];
		int t=pre-x*(j-i+1);
		auto it=s.upper_bound(t);
		s.insert(toadd);
		if(it!=s.end()){
			// cout<<j<<" "<<*it<<"^\n";
			return 1 + f(j+1,n,v,x);
		}
		toadd=t;
	}
	return 0;
}

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v)cin>>x;
	int x;
	cin>>x;
	cout<<n-f(0,n,v,x)<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 30-December-2021 24:14:25 IST