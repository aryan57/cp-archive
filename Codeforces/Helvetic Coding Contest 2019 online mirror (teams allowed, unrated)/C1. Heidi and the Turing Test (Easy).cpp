/*
	group : Codeforces - Helvetic Coding Contest 2019 online mirror (teams allowed, unrated)
	name : C1. Heidi and the Turing Test (Easy).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C1_Heidi_and_the_Turing_Test_Easy_.cpp
	url : https://codeforces.com/problemset/problem/1184/C1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 19:22:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<array<int,2>> v(4*n+1);
	set<array<int,2>> s;

	for(auto &a : v){
		cin>>a[0]>>a[1];
		s.insert(a);
	}

	for(int i=0;i<4*n+1;i++){
		set<int> x,y;
		s.erase(v[i]);

		for(int j=0;j<4*n+1;j++){
			if(i==j)continue;
			x.insert(v[j][0]);
			y.insert(v[j][1]);
		}

		if(x.size()>=2 && y.size()>=2){

			int x1=*x.begin();
			int x2=*x.rbegin();
			int y1=*y.begin();
			int y2=*y.rbegin();

			if(v[i]==(array<int,2>){10,45}){
				cerr<<x1<<" "<<x2<<"^\n";
				cerr<<y1<<" "<<y2<<"^\n";
			}

			bool ok = true;

			// if(ok && s.find({x1,y1})==s.end())ok=false;
			// if(ok && s.find({x1,y2})==s.end())ok=false;
			// if(ok && s.find({x2,y1})==s.end())ok=false;
			// if(ok && s.find({x2,y2})==s.end())ok=false;

			// if(v[i]==(array<int,2>){32,41}){
			// 	cerr<<x1<<" "<<x2<<"^\n";
			// 	cerr<<y1<<" "<<y2<<"^\n";
			// 	cerr<<ok<<"$\n";
			// }

			for(int j=0;j<4*n+1 && ok;j++){
				if(i==j)continue;
				if(v[j][0]==x1 && v[j][1]>=y1 && v[j][1]<=y2)continue;
				if(v[j][0]==x2 && v[j][1]>=y1 && v[j][1]<=y2)continue;
				if(v[j][1]==y1 && v[j][0]>=x1 && v[j][0]<=x2)continue;
				if(v[j][1]==y2 && v[j][0]>=x1 && v[j][0]<=x2)continue;
				ok=false;
			}

			if(ok){
				cout<<v[i][0]<<" "<<v[i][1]<<"\n";
				return;
			}

		}

		s.insert(v[i]);
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
//	parsed : 26-August-2021 19:22:38 IST