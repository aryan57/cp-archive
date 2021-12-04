/*
	group : CodeChef - December Challenge 2021 Division 1 (Unrated)
	name : Valleys and Hills.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Valleys_and_Hills.cpp
	url : https://www.codechef.com/DEC21A/problems/VANDH
*/
/**
 *    author:  Aryan Agarwal
 *    created: 04.12.2021 21:43:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	if(n==m){
		n++;
		cout<<2*n<<"\n";
		while (n--)
			cout<<"01";
		
		cout<<"\n";
		return;
	}

	char z='0';
	char o='1';

	if(n<m){
		swap(n,m);
		swap(z,o);
	}

	string ans="";
	int k=n;
	while (k--){
		ans+=z;
		ans+=o;
	}
	ans+=z;

	int extra=n-1-m;
	
	string s="";
	s+=ans[0];
	for(int i=1;i<ans.size();i++){
		if(ans[i]==o)s+=o;
		else{
			if(extra){s+=z;extra--;}
			s+=z;
		}
	}

	cout<<s.size()<<"\n";
	cout<<s<<"\n";
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
//	parsed : 04-December-2021 21:33:02 IST