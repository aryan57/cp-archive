/*
	group : Codeforces - Codeforces Round #779 (Div. 2)
	name : D2. 388535 (Hard Version).cpp
	srcPath : /home/aryan/cp-workspace/D2_388535_Hard_Version_.cpp
	url : https://codeforces.com/contest/1658/problem/D2
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.03.2022 11:24:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxbit=17;

void solve()
{
	int l,r;
	cin>>l>>r;
	vector <int> a1(r-l+1);
	vector <int> a2(r-l+1);
	for(int &x : a1)cin>>x;
	iota(a2.begin(),a2.end(),l);
	auto get_cnt=[](vector <int> &a)->vector <int> {
		vector <int> cnt(mxbit);
		for(int bit=0;bit<mxbit;bit++){
			for(int x : a){
				if((x>>bit)&1)cnt[bit]++;
			}
		}
		return cnt;
	};

	vector <int> cnt1 = get_cnt(a1);
	vector <int> cnt2 = get_cnt(a2);
	int temp=0;
	int ans=0;
	for(int bit=0;bit<mxbit;bit++){
		if(cnt1[bit]!=cnt2[bit])ans+=(1<<bit);
		else{
			if(2*cnt1[bit]==r-l+1){
				ans+=(1<<bit);
				temp++;
			}
		}
	}


	cout<<ans<<"\n";
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
//	parsed : 29-March-2022 11:24:20 IST