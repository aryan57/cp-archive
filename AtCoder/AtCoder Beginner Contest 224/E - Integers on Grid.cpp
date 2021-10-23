/*
	group : AtCoder - AtCoder Beginner Contest 224
	name : E - Integers on Grid.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Integers_on_Grid.cpp
	url : https://atcoder.jp/contests/abc224/tasks/abc224_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 18:21:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

const int INF = 2e18;

struct node{
	int x,y,a,id;
};

bool comp(node a,node b){
	return a.a>b.a;
}

void solve()
{
	int r,c,n;
	cin>>r>>c>>n;

	vector <vector<pair<int,int> > > mxr(r,vector<pair<int,int> > (2,{-INF,-INF}));
	vector <vector<pair<int,int> > > mxc(c,vector<pair<int,int> > (2,{-INF,-INF}));

	vector <node> v(n);

	for(int i=0;i<n;i++){
		cin>>v[i].x>>v[i].y>>v[i].a;
		v[i].x--;
		v[i].y--;
		v[i].id=i;
	}

	sort(v.begin(),v.end(),comp);
	vector <int> ans(n);

	for(int i=0;i<n;i++){

		int m1 = -INF;
		int m2 = -INF;

		int z=0;

		if(mxr[v[i].x][0].second!=v[i].a)m1=mxr[v[i].x][0].first;
		if(mxr[v[i].x][1].second!=v[i].a)m2=mxr[v[i].x][1].first;

		z=max(z,m1+1);
		z=max(z,m2+1);

		m1 = -INF;
		m2 = -INF;

		if(mxc[v[i].y][0].second!=v[i].a)m1=mxc[v[i].y][0].first;
		if(mxc[v[i].y][1].second!=v[i].a)m2=mxc[v[i].y][1].first;

		z=max(z,m1+1);
		z=max(z,m2+1);

		ans[v[i].id]=z;

		if(mxr[v[i].x][0].second==v[i].a){
			mxr[v[i].x][0].first=max(mxr[v[i].x][0].first,z);
		}
		else if(mxr[v[i].x][1].second==v[i].a){
			mxr[v[i].x][1].first=max(mxr[v[i].x][1].first,z);
		}else{
			if((mxr[v[i].x][0].first <= mxr[v[i].x][1].first) && mxr[v[i].x][0].first<z){
				mxr[v[i].x][0] = {z,v[i].a};
			}
			else if((mxr[v[i].x][0].first >= mxr[v[i].x][1].first) && mxr[v[i].x][1].first<z){
				mxr[v[i].x][1] = {z,v[i].a};
			}
		}

		if(mxc[v[i].y][0].second==v[i].a){
			mxc[v[i].y][0].first=max(mxc[v[i].y][0].first,z);
		}
		else if(mxc[v[i].y][1].second==v[i].a){
			mxc[v[i].y][1].first=max(mxc[v[i].y][1].first,z);
		}else{
			if((mxc[v[i].y][0].first <= mxc[v[i].y][1].first) && mxc[v[i].y][0].first<z){
				mxc[v[i].y][0] = {z,v[i].a};
			}
			else if((mxc[v[i].y][0].first >= mxc[v[i].y][1].first) && mxc[v[i].y][1].first<z){
				mxc[v[i].y][1] = {z,v[i].a};
			}
		}

	}

	for(int x : ans)cout<<x<<"\n";

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
//	parsed : 23-October-2021 18:10:16 IST