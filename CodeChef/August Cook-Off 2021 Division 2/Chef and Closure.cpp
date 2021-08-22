/*
	group : CodeChef - August Cook-Off 2021 Division 2
	name : Chef and Closure.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Chef_and_Closure.cpp
	url : https://www.codechef.com/COOK132B/problems/CLOSCHEF
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 21:51:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	int z=0;
	int o1=0;
	int m1=0;
	int g1=0;
	int gm1=0;

	while(n--){
		int x;
		cin>>x;

		if(x==0){
			z++;
			continue;
		}
		if(x==1){
			o1++;
			continue;
		}
		if(x==-1){
			m1++;
			continue;
		}

		if(x>0){
			g1++;
			continue;
		}
		gm1++;
	}

	if((gm1 && g1) || (g1>1) || (gm1>1) || (g1 && m1) || (gm1 && m1) ||  (m1>1 && o1==0)){
		cout<<"0\n";
		return;
	}

	cout<<"1\n";
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
//	parsed : 22-August-2021 21:49:11 IST