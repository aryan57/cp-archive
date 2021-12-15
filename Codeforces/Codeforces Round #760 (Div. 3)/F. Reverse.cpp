/*
	group : Codeforces - Codeforces Round #760 (Div. 3)
	name : F. Reverse.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F_Reverse.cpp
	url : https://codeforces.com/contest/1618/problem/F
*/
/**
 *    author:  Aryan Agarwal
 *    created: 14.12.2021 22:02:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

string f(int x){
	string z="";

	while (x)
	{
		if(x%2)z+='1';
		else z+='0';
		x/=2;
	}
	reverse(z.begin(),z.end());
	return z;
	
}

bool c(string x,string y){
	int n=x.size();
	int m=y.size();
	if(n>m)return false;
	// if((m-n)%2)reverse(x.begin(),x.end());

	for(int i=0;i<m && i+n-1<=m-1;i++){
		bool zz=true;
		for(int j=0;j<=i-1;j++){
			if(y[j]=='0'){
				zz=false;
				break;
			}
		}
		for(int j=i+n;j<m;j++){
			if(y[j]=='0'){
				zz=false;
				break;
			}
		}
		if(!zz)continue;
		reverse(x.begin(),x.end());

		if(y.substr(i,n)==x)return true;
		reverse(x.begin(),x.end());
		if(y.substr(i,n)==x)return true;
	}
	return false;
}



void solve()
{
	int x,y;
	cin>>x>>y;

	string t=f(x);
	string t1=t+'0';
	string t2=t+'1';
	reverse(t1.begin(),t1.end());
	reverse(t2.begin(),t2.end());

	for(int i=0;i<t1.size();i++){
		if(t1[i]=='1'){
			t1=t1.substr(i);
			break;
		}
	}

	// dbg(t1,t2);


	assert(*t1.begin()=='1' && t1.back()=='1');
	assert(*t2.begin()=='1' && t2.back()=='1');
	string t3=f(y);
	if(c(t1,t3) || c(t2,t3) || x==y || t1==t3 || t2==t3){
		cout<<"YES\n";
	}else{
		cout<<"NO\n";
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
//	parsed : 14-December-2021 22:02:53 IST