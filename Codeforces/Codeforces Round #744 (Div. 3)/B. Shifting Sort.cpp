/*
	group : Codeforces - Codeforces Round #744 (Div. 3)
	name : B. Shifting Sort.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Shifting_Sort.cpp
	url : https://codeforces.com/contest/1579/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.09.2021 20:11:59 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector <int> v(n);

	for(int &x : v){
		cin>>x;
	}

	vector<pair<pair <int,int> ,int> > ans;

	vector <int> z;
	z.push_back(v[0]);

	for(int i=1;i<n;i++){
		int last=-1;

		for(int j=z.size()-1;j>=0;j--){
			if(z[j]<=v[i]){
				last=j;
				break;
			}
		}

		if(last==-1){

			int d=i;

			if(d>0){
				ans.push_back({{0,i},d});
			}

		}else{
			assert(last+1<=i);

			int d=i-last-1;

			if(d>0){
				ans.push_back({{last+1,i},d});
			}

		}


		z.push_back(v[i]);

		sort(z.begin(),z.end());
	} 

	cout<<ans.size()<<"\n";

	for(auto x : ans){
		cout<<x.first.first+1<<" "<<x.first.second+1<<" "<<x.second<<"\n";
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
//	parsed : 28-September-2021 20:09:43 IST