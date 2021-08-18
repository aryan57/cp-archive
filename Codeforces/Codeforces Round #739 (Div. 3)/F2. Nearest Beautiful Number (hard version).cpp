/*
	group : Codeforces - Codeforces Round #739 (Div. 3)
	name : F2. Nearest Beautiful Number (hard version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/F2_Nearest_Beautiful_Number_hard_version_.cpp
	url : https://codeforces.com/contest/1560/problem/F2
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.08.2021 21:17:18 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;

	string s=to_string(n);

	set<char> qq;

	for(char x : s){
		qq.insert(x);
	}

	if(qq.size() <= k){
		cout<<s<<"\n";
		return;
	}

	int z=s.size();

	int ans=stoll(string(z+1,'1'));

	// cout<<ans<<"\n";
	int tot=0;
	int cnt[10]={};
	for(int i=0;i<z;i++){

		// if(s[i]=='9')continue;

		bool found=false;

		for(int j=s[i]-'0'+1;j<=9;j++){

			if(cnt[j]>0){
				string temp=s.substr(0,i);
				temp+='0'+j;

				int rem=z-i-1;

				if(rem==0){
					found=true;
					ans=min(ans,(long long)stoll(temp));
					break;
				}

				if(tot<k){
					found=true;
					temp+=string(rem,'0');
					ans=min(ans,(long long)stoll(temp));
					break;

				}

				for(int t=0;t<=9;t++){
					if(cnt[t]>0){
						found=true;
						temp+=string(rem,'0'+t);
						ans=min(ans,(long long)stoll(temp));
						break;
					}
				}

				if(found)break;

			}else if(tot<k){

				int ntot=tot+1;

				string temp=s.substr(0,i);
				temp+='0'+j;

				int rem=z-i-1;

				if(rem==0){
					found=true;
					ans=min(ans,(long long)stoll(temp));
					break;
				}

				if(ntot<k){
					found=true;
					temp+=string(rem,'0');
					ans=min(ans,(long long)stoll(temp));
					break;

				}

				for(int t=0;t<=9;t++){
					if(cnt[t]>0 || t==j){
						found=true;
						temp+=string(rem,'0'+t);
						ans=min(ans,(long long)stoll(temp));
						break;
					}
				}

				if(found)break;

			}

		}

		cnt[s[i]-'0']++;
		if(cnt[s[i]-'0']==1)tot++;
		if(tot==k+1)break;
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
//	parsed : 18-August-2021 21:11:40 IST
//	parsed : 18-August-2021 21:35:36 IST