/*
	group : Codeforces - Codeforces Round #579 (Div. 3)
	name : D2. Remove the Substring (hard version).cpp
	srcPath : /home/aryan/Desktop/cp-workspace/D2_Remove_the_Substring_hard_version_.cpp
	url : https://codeforces.com/problemset/problem/1203/D2
*/
/**
 *    author:  Aryan Agarwal
 *    created: 26.08.2021 08:45:31 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

vector<int> f(string s,string t){

	int n=s.size();
	int m=t.size();

	vector<int> ans(n,0);

	int prev=-1;

	for(int j=0;j<m;j++){

		for(int i=prev+1;i<n;i++){
			if(t[j]==s[i]){
				ans[i]=j+1;
				prev=i;
				break;
			}
		}

	}
	for(int i=1;i<n;i++){
		ans[i]=max(ans[i],ans[i-1]);
	}

	return ans;
}

void solve()
{
	string s,t;
	cin>>s>>t;

	int n=s.size();
	int m=t.size();

	vector<int> left = f(s,t);
	reverse(s.begin(),s.end());
	reverse(t.begin(),t.end());
	vector<int> right = f(s,t);
	reverse(right.begin(),right.end());

	int ans=0;
	int start=0;
	for(int i=0;i<n;i++){
		
		if(left[i]==m){
			ans=max(ans,n-i-1);
			break;
		}

		if(right[i]==m){
			ans=max(ans,i);
		}

		for(int j=max(i+1,start);j<n;j++){
			if(right[j] + left[i]>=m){
				ans=max(ans,j-i-1);
				start=j;	
			}else{
				break;
			}
		}

	}

	cout<<ans;
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
//	parsed : 26-August-2021 08:38:56 IST