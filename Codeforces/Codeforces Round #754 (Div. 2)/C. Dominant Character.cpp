/*
	group : Codeforces - Codeforces Round #754 (Div. 2)
	name : C. Dominant Character.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Dominant_Character.cpp
	url : https://codeforces.com/contest/1605/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 13.11.2021 10:48:27 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	for(int l=2;l<=10;l++){
		for(int i=0;i<=n-l;i++){

			int cnt[3]={};

			for(int j=i;j<=i+l-1;j++){
				cnt[s[j]-'a']++;
			}

			if(cnt[0]>cnt[1] && cnt[0]>cnt[2]){
				cout<<l;
				cout<<"\n";
				return;
			}
		}
	}

	cout<<"-1\n";
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
//	parsed : 13-November-2021 10:48:22 IST