/*
	group : Codeforces - Codeforces Round #741 (Div. 2)
	name : D1. Two Hundred Twenty One (easy version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D1_Two_Hundred_Twenty_One_easy_version_.cpp
	url : https://codeforces.com/contest/1562/problem/D1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 21:35:43 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,q;
	cin>>n>>q;

	string s;
	cin>>s;

	s='#'+s;

	vector<int> p1(n+1);
	vector<int> p2(n+1);

	for(int i=1;i<=n;i+=1){
		p1[i]+=p1[i-1];
		if(i%2){
			if(s[i]=='+')p1[i]++;
			else p1[i]--;
		}
	}

	for(int i=1;i<=n;i+=1){
		p2[i]+=p2[i-1];
		if(i%2==0){
			if(s[i]=='-')p2[i]++;
			else p2[i]--;
		}
	}


	while(q--){
		int l,r;
		cin>>l>>r;
		int s1=p1[r]-p1[l-1];
		int s2=p2[r]-p2[l-1];
		int sum=abs(s1+s2);

		if(sum==0){
			cout<<0<<"\n";
			continue;
		}

		if(sum%2){
			cout<<1<<"\n";
			continue;
		}

		cout<<2<<"\n";
	}
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
//	parsed : 26-August-2021 20:59:54 IST