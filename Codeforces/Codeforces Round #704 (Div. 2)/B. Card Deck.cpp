/*
	group : Codeforces - Codeforces Round #704 (Div. 2)
	name : B. Card Deck.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Card_Deck.cpp
	url : https://codeforces.com/problemset/problem/1492/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 24.08.2021 19:28:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<pair<int,int>> v(n);
	vector<int> a(n);

	for(int i=0;i<n;i++){
		cin>>v[i].first;
		v[i].second=i;
		a[i]=v[i].first;
	}

	sort(v.begin(),v.end(),greater<pair<int,int>> () );

	int last=n;

	vector<int> ans(n);
	int ind=0;

	for(int i=0;i<n;i++){
		if(v[i].second<last){

			for(int j=v[i].second;j<n && j<last;j++){
				ans[ind++]=a[j];
			}
			last=v[i].second;
		}
	}

	for(int x : ans)cout<<x<<" ";
	cout<<"\n";

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
//	parsed : 24-August-2021 19:25:47 IST