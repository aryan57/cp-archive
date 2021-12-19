/*
	group : Codeforces - Codeforces Round #761 (Div. 2)
	name : D1. Too Many Impostors (easy version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D1_Too_Many_Impostors_easy_version_.cpp
	url : https://codeforces.com/contest/1617/problem/D1
*/
/**
 *    author:  Aryan Agarwal
 *    created: 16.12.2021 21:29:58 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;
	int crew=-1;
	int imposter=-1;
	vector <int> v(n);
	for(int i=0;i<n;i++){
		int a=i+1;
		int b=(i+1)%n+1;
		int c=(i+2)%n+1;
		cout<<"? "<<a<<" "<<b<<" "<<c;
		cout<<endl;
		cin>>v[i];
	}
	int prev=v[n-1];
	for(int i=0;i<n;i++){
		int a=i+1;
		int b=(i+1)%n+1;
		int c=(i+2)%n+1;
		if(i && v[i]!=prev){
			int z=((c-4)%n+n)%n+1;
			if(prev==1){
				crew=z;
				imposter=c;
			}else{
				crew=c;
				imposter=z;
			}
			break;
		}
		prev=v[i];
	}
	vector <int> ans;
	for(int i=1;i<=n;i++){
		cout<<"? "<<crew<<" "<<imposter<<" "<<i;
		cout<<endl;
		int x;
		cin>>x;
		if(x==0)ans.push_back(i);
	}
	cout<<"! ";
	cout<<ans.size()<<" ";
	for(int x : ans)cout<<x<<" ";
	cout<<endl;
}

signed main()
{
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 16-December-2021 20:29:12 IST