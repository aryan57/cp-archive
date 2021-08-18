/*
	group : Codeforces - Codeforces Round #739 (Div. 3)
	name : D. Make a Power of Two.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D_Make_a_Power_of_Two.cpp
	url : https://codeforces.com/contest/1560/problem/D
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.08.2021 20:41:25 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int INF = 2e18;
vector<string> pw;

void pre(){

	int z=1;
	while(z<=INF){
		pw.push_back(to_string(z));
		z*=2;
	}
	
}

int f(string t,string s){

	int n=t.size();
	int m=s.size();

	int i=0;int j=0;

	int cnt=0;

	while(i<n && j<m){

		if(t[i]==s[j]){
			i++;
			j++;
			continue;
		}

		j++;
		cnt++;
	}

	cnt+=n-i;
	cnt+=m-j;

	return cnt;

}

void solve()
{
	string n;
	cin>>n;

	int ans=n.size();
	ans++;

	for(string t : pw){
		ans=min(ans,f(t,n));
	}

	cout<<ans<<"\n";

}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	pre();

	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 18-August-2021 20:38:52 IST