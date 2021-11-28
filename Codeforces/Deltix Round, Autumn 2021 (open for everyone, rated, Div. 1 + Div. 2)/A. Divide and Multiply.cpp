/*
	group : Codeforces - Deltix Round, Autumn 2021 (open for everyone, rated, Div. 1 + Div. 2)
	name : A. Divide and Multiply.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Divide_and_Multiply.cpp
	url : https://codeforces.com/contest/1609/problem/0
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.11.2021 20:07:20 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <int> v(n);
	for(int &x : v){
		cin>>x;
	}

	int ans=0;

	for(int i=0;i<n;i++){
		vector <int> t(v);
		for(int j=0;j<n;j++){
			if(i==j)continue;
			while (t[j]%2==0)
			{
				t[j]/=2;
				t[i]*=2;
			}
		}
		ans=max(ans,accumulate(t.begin(),t.end(),0ll));
	}
	cout<<ans<<"\n";
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
//	parsed : 28-November-2021 20:05:40 IST