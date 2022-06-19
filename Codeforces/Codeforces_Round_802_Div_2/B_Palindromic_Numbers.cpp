/**
 *    author:  Aryan Agarwal
 *    created: 19.06.2022 14:48:42 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

string f(string a, string b){
	int k=b.size();
	string ans(k,'0');
	int carry=0;

	for(int i=k-1;i>=1;i--){
		if(a[i]>=b[i]){
			ans[i] = '0' + a[i] - b[i];
		}else{
			a[i-1]='0';
			int sum = 10 + (a[i]-'0');
			assert(sum>=b[i]-'0');
			ans[i] = '0' + sum-(b[i]-'0');
		}
	}
	assert(a[0]=='0');
	ans.erase(ans.begin());
	return ans;
}

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	if(s[0]!='9'){
		for(int i=0;i<n;i++){
			int d1=s[i]-'0';
			d1=9-d1;
			cout<<char('0'+d1);
		}
		cout<<"\n";
		return;
	}
	string k(n+1,'1');
	s="0"+s;
	string ans = f(k,s);
	assert(ans.size()==n);
	cout<<ans;
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