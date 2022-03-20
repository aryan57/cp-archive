/*
	group : Google Coding Competitions - Round A 2022 - Kick Start 2022
	name : Palindrome Free Strings.cpp
	srcPath : /home/aryan/cp-workspace/Palindrome_Free_Strings.cpp
	url : https://codingcompetitions.withgoogle.com/kickstart/round/00000000008cb33e/00000000009e762e
*/
/**
 *    author:  Aryan Agarwal
 *    created: 20.03.2022 11:22:40 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int get_bit(int num,int b){
	return ((num>>b)&1);
}

bool check(int num2,int num){
	for(int i=1;i<=4;i++){
		if(get_bit(num,i)!=get_bit(num2,i-1))return true;
	}
	return false;
}

bool pali(int num){

	for(int i=0;i<=2;i++){
		if(get_bit(num,i)!=get_bit(num,5-i))return false;
	}
	return true;
}

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;

	if(n<5){
		cout<<"POSSIBLE\n";
		return;
	}

	vector< vector<bool> > dp(n,vector <bool> (32,false));
	vector <int> bits;
	for(int num=0;num<32;num++){
		if(get_bit(num,0)==get_bit(num,4) && get_bit(num,1)==get_bit(num,3))continue;
		bits.push_back(num);
	}

	for(int i=2;i<=n-3;i++){
		for(int num : bits){

			if(s[i-2]!='?' && s[i-2]-'0'!=get_bit(num,4))continue;
			if(s[i-1]!='?' && s[i-1]-'0'!=get_bit(num,3))continue;
			if(s[i]!='?' && s[i]-'0'!=get_bit(num,2))continue;
			if(s[i+1]!='?' && s[i+1]-'0'!=get_bit(num,1))continue;
			if(s[i+2]!='?' && s[i+2]-'0'!=get_bit(num,0))continue;

			if(i==2){
				dp[i][num]=true;
				continue;
			}
			for(int num2 : bits){
				if(s[i-2-1]!='?' && s[i-2-1]-'0'!=get_bit(num2,4))continue;
				if(s[i-1-1]!='?' && s[i-1-1]-'0'!=get_bit(num2,3))continue;
				if(s[i-1]!='?' && s[i-1]-'0'!=get_bit(num2,2))continue;
				if(s[i+1-1]!='?' && s[i+1-1]-'0'!=get_bit(num2,1))continue;
				if(s[i+2-1]!='?' && s[i+2-1]-'0'!=get_bit(num2,0))continue;

				int z=num2*2+get_bit(num,0);
				if(!dp[i-1][num2] || check(num2,num) || pali(z))continue;
				dp[i][num]=true;
				break;
			}
		}
	}

	for(int num : bits){
		if(dp[n-3][num]){
			cout<<"POSSIBLE\n";
			return;
		}
	}
	cout<<"IMPOSSIBLE\n";
	return;
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}