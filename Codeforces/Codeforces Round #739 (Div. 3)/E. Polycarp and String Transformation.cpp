/*
	group : Codeforces - Codeforces Round #739 (Div. 3)
	name : E. Polycarp and String Transformation.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/E_Polycarp_and_String_Transformation.cpp
	url : https://codeforces.com/contest/1560/problem/E
*/
/**
 *    author:  Aryan Agarwal
 *    created: 18.08.2021 21:01:49 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	string s;
	cin>>s;

	int n=s.size();

	s='#'+s;

	string t="";
	int cnt[26]={};

	for(int i=n;i>=1;i--){
		cnt[s[i]-'a']++;
		if(cnt[s[i]-'a']==1){
			t+=s[i];
		}
	}

	reverse(t.begin(),t.end());

	// cerr<<t<<"\n";

	for( int & x : cnt)x=0;
	// string z="";
	for(int i=1;i<=n;i++){
		cnt[s[i]-'a']++;
		// z+=s[i];
		int sum=i;
		int cur=i;
		for(char c : t){
			cur-=cnt[c-'a'];
			assert(cur>=0);
			sum+=cur;
		}

		if(sum==n){

			int ind=i+1;
			bool ok = true;

			vector<bool> vis(26,false);

			 for(char c : t){
				vis[c-'a']=true;
				
				for(int j=1;j<=i;j++){
					if(!vis[s[j]-'a']){
						if(s[ind]!=s[j]){
							ok=false;
							break;
						}
						ind++;
					}
				}

				if(!ok)break;

			}

			if(ok){
				cout<<s.substr(1,i)<<" "<<t<<"\n";
				return;
			}

		}

	}

	cout<<"-1\n";
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
//	parsed : 18-August-2021 20:51:58 IST