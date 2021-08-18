/*
	group : AtCoder - AtCoder Beginner Contest 213
	name : E - Stronger Takahashi.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Stronger_Takahashi.cpp
	url : https://atcoder.jp/contests/abc213/tasks/abc213_e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 08.08.2021 18:35:08 IST
**/
#include <bits/stdc++.h>
using namespace std;

vector<int> hx={0,1,0,-1};
vector<int> hy={-1,0,1,0};

bool is_inside(int x,int y,int n,int m){
	return (x>=0 && x<n && y>=0 && y<m);
}

const int mxn=500*500;

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<vector<int>> g(n,vector<int> (m));

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			char x;
			cin>>x;
			if(x=='#')g[i][j]=1;
		}
	}

	vector<vector<int>> d(n,vector<int> (m,1e9));

	deque<pair<int,int>> q;
	q.push_front({0,0});
	d[0][0]=0;

	while(!q.empty()){

		auto p=q.front();
		q.pop_front();
		int x=p.first;
		int y=p.second;

		for(int k=0;k<4;k++){
			int r=x+hx[k];
			int c=y+hy[k];
			if(!is_inside(r,c,n,m) || g[r][c])continue;

			if(d[r][c]>d[x][y]){
				d[r][c]=d[x][y];
				q.push_front({r,c});
			}
			
		}

		for(int i=x-2;i<=x+2;i++){
			for(int j=y-2;j<=y+2;j++){
				if(!is_inside(i,j,n,m) || (i==x && j==y) || (abs(i-x)+abs(j-y)==4))continue;
				if(d[i][j]>d[x][y]+1){
					d[i][j]=d[x][y]+1;
					q.push_back({i,j});
				}
			}
		}

	}

	cout<<d[n-1][m-1];
	
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
//	parsed : 08-August-2021 18:07:03 IST