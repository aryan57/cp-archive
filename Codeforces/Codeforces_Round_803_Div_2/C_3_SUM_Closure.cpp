/**
 *    author:  Aryan Agarwal
 *    created: 29.06.2022 03:34:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool brute(vector <int> &v){
	int n=v.size();
	for(int i=0;i<n;i++){
		for(int j=i+1;j<n;j++){
			for(int k=j+1;k<n;k++){
				if(!binary_search(v.begin(),v.end(),v[i]+v[j]+v[k]))return false;
			}
		}
	}
	return true;
}

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	int p=0;
	int m=0;
	int z=0;
	for(int &x : v){
		cin>>x;
		if(x==0)z++;
		if(x>0)p++;
		if(x<0)m++;
	}
	
	sort(v.begin(),v.end());
	

	if(p>=3 || m>=3){
		cout<<"NO\n";
		return;
	}

	if(n<=100){
		if(brute(v))cout<<"YES\n";
		else cout<<"NO\n";
		return;
	}

	if(p==2 || m==2){
		cout<<"NO\n";
		return;
	}

	assert(z>50 && p<=1 && m<=1);

	if(p==0 || m==0){
		cout<<"YES\n";
		return;
	}


	if(v[0]+v[n-1]){
		cout<<"NO\n";
		return;
	}

	cout<<"YES\n";
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