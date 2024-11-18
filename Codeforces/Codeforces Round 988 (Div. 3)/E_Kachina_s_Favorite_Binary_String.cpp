/**
 *    author:  Aryan Agarwal
 *    created: 17.11.2024 21:05:01 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;

	string s="";
	int prev=-1;
	int cur=0;
	bool nonZeroFound = false;

	for(int i=2;i<=n;i++){
		cout<<"? 1 "<<i<<endl;
		cin>>cur;

		if(cur==0)continue;

		if(!nonZeroFound){
			nonZeroFound = true;
			s += string( i - 1 - cur, '1');
			s += string( cur, '0');
			s += '1';
		}else{
			if(prev==cur){
				s+='0';
			}else{
				s+='1';
			}
		}
		prev = cur;
	}
	if(prev==-1){
		cout<<"! IMPOSSIBLE"<<endl;
	}
	else{
		cout<<"! "<<s<<endl;
	}

}

signed main()
{
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		solve();
	}
	return 0;
}