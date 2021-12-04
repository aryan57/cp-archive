/*
	group : CodeChef - December Challenge 2021 Division 1 (Unrated)
	name : Increasing String .cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Increasing_String_.cpp
	url : https://www.codechef.com/DEC21A/problems/INCREAST
*/
/**
 *    author:  Aryan Agarwal
 *    created: 03.12.2021 19:08:24 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	string s;
	cin>>s;
	int n=s.size();

	vector<int> lastpos(26);
	vector<char> mn(n);
	mn[n-1]=s[n-1];
	for(int i=n-2;i>=0;i--)
		mn[i]=min(mn[i+1],s[i]);
	
	for(int i=0;i<n;i++)
		lastpos[s[i]-'a']=i;
	
	int i=0;
	string took="",not_took="";
	while (i<n)
	{
		char mnn=mn[i];
		if(!not_took.empty() && mnn>=not_took[0]){
			if(mnn>not_took[0]){
				not_took+=s.substr(i);
				break;
			}
			char x = not_took[0];
			char y='0';
			for(char tt : not_took){
				if(tt!=x){
					y=tt;
					break;
				}
			}
			if(y!='0' && y<x){
				not_took+=s.substr(i);
				break;
			}
			for(int j=i;j<n;j++){
				if(s[j]==x)took+=s[j];
				else not_took+=s[j];
			}
			break;
		}
		for(int j=i;j<=lastpos[mnn-'a'];j++){
			if(s[j]==mnn)took+=s[j];
			else not_took+=s[j];
		}
		i=lastpos[mnn-'a']+1;
	}
	cout<<took+not_took<<"\n";
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
//	parsed : 03-December-2021 19:07:46 IST