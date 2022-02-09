/*
	group : local
	name : c.cpp
	srcPath : /home/aryan/Downloads/c.cpp
	url : /home/aryan/Downloads/c.cpp
*/
/**
 *    author:  Aryan Agarwal
 *    created: 09.02.2022 19:36:39 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int f(int a,int b){
	if(a==b)return 0;

	if(a<b){
		int ans=b-a;
		if(2*a<=b)ans=min(ans,1+b/2-a+f(2*(a+b/2-a),b));
		return ans;
	}else{
		if(a%2==0 && a)return 1+f(a/2,b);
		else return 1+f(a+1,b);
	}
}

void solve()
{
	int a,b;
	cin>>a>>b;
	cout<<f(a,b)<<"\n";
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