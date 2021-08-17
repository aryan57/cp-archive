/*
	group : CodeChef - CodeChef Starters 9 Division 2 (Unrated)
	name : Friend Groups In A Line.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Friend_Groups_In_A_Line.cpp
	url : https://www.codechef.com/START9B/problems/FRIENDGR
*/
/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 20:19:21 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	int ans=0;

	set<int,greater<int>> s;

	for(int i=0;i<n;i++){
		char z;
		cin>>z;
		if(z=='0')continue;

		if(s.empty()){
			s.insert(i+1);
			ans++;
			continue;
		}

		if(*s.begin() + k >= i + 1){
			s.insert(i+1);
			continue;
		}
		if(*s.begin() + k == i){
			s.insert(i);
			continue;
		}
		if(*s.begin() + k == i-1){
			s.insert(i-1);
			s.clear();
			continue;
		}

		s.clear();
		s.insert(i+1);
		ans++;
	}

	cout<<ans<<"\n";
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
//	parsed : 17-August-2021 20:12:02 IST