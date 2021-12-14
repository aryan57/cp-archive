/*
	group : Codeforces - Codeforces Round #760 (Div. 3)
	name : A. Polycarp and Sums of Subsequences.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Polycarp_and_Sums_of_Subsequences.cpp
	url : https://codeforces.com/contest/1618/problem/A
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.12.2021 20:25:09 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	vector <int> b(7);
	cin>>b[0]>>b[1];
	int xx=-1;
	for(int i=2;i<7;i++){
		cin>>b[i];
	}
	for(int i=2;i<7;i++){
		vector <int> t;
		vector <int> t2={b[0],b[1],b[i]};
		for(int num=1;num<8;num++){
			int s=0;
			for(int bit=0;bit<3;bit++){
				if((num>>bit)&1)s+=t2[bit];
			}
			t.push_back(s);
		}
		// dbg(t,t2,b);
		sort(t.begin(),t.end());
		if(t==b)xx=i;
	}

	cout<<b[0]<<" "<<b[1]<<" "<<b[xx]<<"\n";

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
//	parsed : 14-December-2021 20:23:54 IST