/*
	group : AtCoder - AtCoder Beginner Contest 213
	name : C - Reorder Cards.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Reorder_Cards.cpp
	url : https://atcoder.jp/contests/abc213/tasks/abc213_c
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.08.2021 17:35:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int h,w,n;
	cin>>h>>w>>n;

	vector<pair<int,int> > vx(n);
	vector<pair<int,int> > vy(n);
	vector<pair<int,int> > ans(n);

	for(int i=0;i<n;i++){
		cin>>vx[i].first>>vy[i].first;
		vx[i].second=i;
		vy[i].second=i;
	}

	sort(vx.begin(),vx.end());
	sort(vy.begin(),vy.end());

	int cx=1;
	int cy=1;

	ans[vx[0].second].first=1;
	ans[vy[0].second].second=1;

	for(int i=1;i<n;i++)
	{
		if(vx[i].first!=vx[i-1].first)cx++;
		if(vy[i].first!=vy[i-1].first)cy++;

		ans[vx[i].second].first=cx;
		ans[vy[i].second].second=cy;
	}

	for(int i=0;i<n;i++){
		cout<<ans[i].first<<" "<<ans[i].second<<"\n";
	}

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 08-August-2021 17:34:52 IST