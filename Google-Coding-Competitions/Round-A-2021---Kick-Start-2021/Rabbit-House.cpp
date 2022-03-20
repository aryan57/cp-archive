/*
	group : Google Coding Competitions - Round A 2021 - Kick Start 2021
	name : Rabbit House.cpp
	srcPath : /home/aryan/cp-workspace/Rabbit_House.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/0000000000436140/000000000068cb14
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 09:19:23 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int r,c;
	cin>>r>>c;
	vector< vector<int> > g(r,vector <int> (c));
	priority_queue<pair<int,pair <int,int> >, vector<pair<int,pair <int,int> >>,greater<>> pq;
	for(int i=0;i<r;i++){
		for(int j=0;j<c;j++){
			cin>>g[i][j];
			pq.push({g[i][j],{i,j}});
		}
	}

	vector <int> hx={-1,0,1,0};
	vector <int> hy={0,1,0,-1};

	int ans=0;

	while (!pq.empty())
	{
		auto z = pq.top();
		pq.pop();
		vector <int> temp;
		int mx=0;
		for(int k=0;k<4;k++){
			int rr=z.second.first+hx[k];
			int cc=z.second.second+hy[k];
			if(rr>=0 && cc>=0 && rr<r && cc<c){
				mx=max(mx,g[rr][cc]-1-g[z.second.first][z.second.second]);
			}
		}
		if(mx!=0){
			ans+=mx;
			g[z.second.first][z.second.second]+=mx;
			pq.push({g[z.second.first][z.second.second],{z.second.first,z.second.second}});
		}
	}
	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}
//	parsed : 20-March-2022 09:19:16 IST