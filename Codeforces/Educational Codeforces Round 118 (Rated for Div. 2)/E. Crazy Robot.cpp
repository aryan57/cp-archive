/*
	group : Codeforces - Educational Codeforces Round 118 (Rated for Div. 2)
	name : E. Crazy Robot.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Crazy_Robot.cpp
	url : https://codeforces.com/contest/1613/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 01.12.2021 23:38:56 IST
**/
#include <bits/stdc++.h>
using namespace std;

vector<int> plus_x={0,1,0,-1};
vector<int> plus_y={-1,0,1,0};

bool is_inside(int x,int y,int n,int m)
{
	return (x>=0 && x<n && y>=0 && y<m);
}

void solve()
{
	int n,m;
	cin>>n>>m;
	vector< vector<char> > g(n, vector <char>(m));
	vector< vector<bool> > visited(n, vector <bool>(m));
	queue< pair <int,int> > q;

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++){
			cin>>g[i][j];
			if(g[i][j]=='L'){
				q.push({i,j});
				visited[i][j]=true;
			}
		}
	}

	while (!q.empty()) {
	
		pair <int,int> parent_node = q.front();
		q.pop();
		int x=parent_node.first;
		int y=parent_node.second;
		for(int k=0;k<4;k++){
			int r=plus_x[k]+x;
			int c=plus_y[k]+y;
			if(!is_inside(r,c,n,m) || g[r][c]!='.')continue;
			int ava=0;
			for(int k2=0;k2<4;k2++){
				int r2=plus_x[k2]+r;
				int c2=plus_y[k2]+c;
				if(is_inside(r2,c2,n,m) && g[r2][c2]=='.')ava++;
			}
			if(ava<=1){
				g[r][c]='+';
				visited[r][c]=true;
				q.push({r,c});
			}
		}
	}

	for(int i=0;i<n;i++){
		for(int j=0;j<m;j++)
			cout<<g[i][j];
			cout<<"\n";
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
//	parsed : 01-December-2021 23:38:50 IST