/*
	group : CodeChef - December Challenge 2021 Division 1 (Unrated)
	name : Squares Counting.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Squares_Counting.cpp
	url : https://www.codechef.com/DEC21A/problems/GRIDSQRS
*/
/**
 *    author:  Aryan Agarwal
 *    created: 04.12.2021 19:35:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
using namespace __gnu_pbds;
typedef tree<int, null_type, less<int>, rb_tree_tag,tree_order_statistics_node_update> ordered_set; 

void solve()
{
	int n;
	cin>>n;
	string s;
	int g[n+2][n+2]={};
	vector<pair<int,int> > points [2*n+1];
	for(int i=1;i<=n;i++){
		cin>>s;
		for(int j=1;j<=n;j++){
			g[i][j] = s[j-1]-'0';
			points[i+j].push_back({i,j});
		}
	}

	int d[n+2][n+2]={};
	int u[n+2][n+2]={};

	for(int i=1;i<=n;i++){
		int last=0;
		for(int j=1;j<=n;j++){
			if(g[i][j]==0)last=j;
			d[i][j]=j-last;
		}
		last=n+1;
		for(int j=n;j>=1;j--){
			if(g[i][j]==0)last=j;
			u[i][j]=last-j;
		}
	}
	for(int j=1;j<=n;j++){
		int last=0;
		for(int i=1;i<=n;i++){
			if(g[i][j]==0)last=i;
			u[i][j]=min(u[i][j],i-last);
		}
		last=n+1;
		for(int i=n;i>=1;i--){
			if(g[i][j]==0)last=i;
			d[i][j]=min(d[i][j],last-i);
		}
	}

	int cnt=0;

	for(auto v : points){
		ordered_set x;
		priority_queue<pair <int,int>,vector<pair<int,int> > , greater<> > pq;
		for(auto p : v){
			pq.push({d[p.first][p.second]+p.first-1,p.first});
		}
		for(auto p : v){
			x.insert(p.first);
			while (!pq.empty() && pq.top().first < p.first){
				x.erase(pq.top().second);
				pq.pop();
			}
			cnt+=x.size() - x.order_of_key(-u[p.first][p.second]+p.first+1);
		}
	}
	cout<<cnt<<"\n";
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
//	parsed : 04-December-2021 19:34:56 IST