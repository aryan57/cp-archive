/*
	group : CodeChef - Infinity 2k21 Division 1 (Unrated)
	name : Marbles.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Marbles.cpp
	url : https://www.codechef.com/INFI21A/problems/MARBLE
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.12.2021 20:03:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

bool vow(char x){
	if(x=='a')return true;
	if(x=='e')return true;
	if(x=='i')return true;
	if(x=='o')return true;
	if(x=='u')return true;
	return false;
}

void solve()
{
	int n;
	cin>>n;
	const int INF = 2e18;
	int ans=INF;

	string s,t;
	cin>>s>>t;

	string a,b;
	a=s;
	b=t;
	for(char x='a';x<='z';x++){
		
		for(int i=0;i<n;i++){
			if(s[i]=='?')a[i]=x;
			else a[i]=s[i];

			if(t[i]=='?')b[i]=x;
			else b[i]=t[i];
		}
		int cnt=0;
		for(int i=0;i<n;i++){
			if(b[i]!=a[i]){
				cnt+=1;
				if(!(vow(b[i])^vow(a[i])))cnt++;
			}
		}
		ans=min(ans,cnt);
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
//	parsed : 22-December-2021 20:03:36 IST