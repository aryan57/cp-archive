/**
 *    author:  Aryan Agarwal
 *    created: 13.05.2022 16:27:10 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int rem=k;
	vector<int> f(n);
	int id=0;
	for(char x : s){
		if(x=='0'){
			if(k%2==0){
				if(rem){
					rem--;
					f[id]=1;
				}else break;
			}
		}else{
			if(k%2==1){
				if(rem){
					rem--;
					f[id]=1;
				}else break;
			}
		}
		id++;
	}
	f[n-1]+=rem;

	for(int i=0;i<n;i++){

		if(k%2!=f[i]%2)s[i]^='1'^'0';
		cout<<s[i];
	}
	cout<<"\n";
	for(int x : f){
		cout<<x<<" ";
	}
	cout<<"\n";
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