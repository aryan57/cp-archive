/*
	group : AtCoder - AtCoder Beginner Contest 224
	name : B - Mongeness.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Mongeness.cpp
	url : https://atcoder.jp/contests/abc224/tasks/abc224_b
*/
/**
 *    author:  Aryan Agarwal
 *    created: 23.10.2021 17:31:48 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int h,w;
	cin>>h>>w;
	vector< vector<int> > g(h+1,vector <int> (w+1));

	for(int i=1;i<=h;i++){
		for(int j=1;j<=w;j++){
			cin>>g[i][j];
		}
	}

	bool ok = true;

	for(int i=1;i<=h;i++){
		for(int i2=i+1;i2<=h;i2++){
			for(int j=1;j<=w;j++){
				for(int j2=j+1;j2<=w;j2++){
					if(g[i][j]+g[i2][j2] > g[i2][j] + g[i][j2]){
						cout<<"No";
						return;
					}
				}
			}
		}
		
	}

	cout<<"Yes";

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
//	parsed : 23-October-2021 17:31:43 IST