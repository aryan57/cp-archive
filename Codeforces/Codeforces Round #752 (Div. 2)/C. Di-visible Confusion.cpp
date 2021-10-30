/*
	group : Codeforces - Codeforces Round #752 (Div. 2)
	name : C. Di-visible Confusion.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Di_visible_Confusion.cpp
	url : https://codeforces.com/contest/1604/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.10.2021 20:43:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	deque<int> d;

	for(int i=0;i<n;i++){
		int x;
		cin>>x;
		d.push_back(x);
	}

	
	int odd=0;
	while (!d.empty())
	{
		while (!d.empty())
		{
			if(d.front()%2){
				odd++;
				d.pop_front();
				continue;
			}
			break;
		}

		if(d.empty()){
			odd=0;
			break;
		}

		bool cont=false;

		for(int rem=0;rem<=odd;rem++){
			if(d.front()%(odd-rem+2)){
				odd-=rem;
				d.pop_front();
				cont=true;
				break;
			}
		}

		if(cont)continue;

		cout<<"NO\n";
		return;
	}

	cout<<"YES\n";
	
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
//	parsed : 30-October-2021 20:30:38 IST