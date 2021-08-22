/*
	group : CodeChef - August Cook-Off 2021 Division 2
	name : Different String.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Different_String.cpp
	url : https://www.codechef.com/COOK132B/problems/DIFSTR
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 21:44:17 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	vector<string> v(n);

	for(string &s : v)cin>>s;

	for(int i=1;i<=110;i++){

		string z="";
		int num=i;
		int rem=n;
		while(num){
			z+='0'+num%2;
			num/=2;
			rem--;
		}

		if(rem>0)z+=string(rem,'0');
		z=z.substr(0,n);
		reverse(z.begin(),z.end());


		bool ok = true;

		for(auto s : v){
			if(s==z){
				ok=false;
				break;
			}
		}

		if(ok){
			cout<<z<<"\n";
			return;
		}



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
//	parsed : 22-August-2021 21:42:46 IST