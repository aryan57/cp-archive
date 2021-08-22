/*
	group : AtCoder - AtCoder Regular Contest 125
	name : A - Dial Up.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/A_Dial_Up.cpp
	url : https://atcoder.jp/contests/arc125/tasks/arc125_a
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 18:03:57 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,m;
	cin>>n>>m;

	vector<int> s(2*n),t(m);

	for(int i=0;i<n;i++){
		cin>>s[i];
		s[i+n]=s[i];
	}

	int ans=m;

	int cur=n;

	for(int i=0;i<m;i++){
		int x;
		cin>>x;
		if(x==s[cur])continue;
		
		int j=-1;
		int k=-1;
		if(cur+1<2*n && s[cur+1]==x){
			ans++;
			cur++;
			continue;
		}
		if(cur-1>=0 && s[cur-1]==x){
			ans++;
			cur--;
			continue;
		}

		for(int z=cur+1;z<2*n;z++){
			if(s[z]==x){
				j=z;
				break;
			}
		}
		for(int z=cur-1;z>=0;z--){
			if(s[z]==x){
				k=z;
				break;
			}
		}

		if(j==-1 && k==-1){
			cout<<"-1\n";
			return;
		}
		if(j==-1){
			ans+=abs(cur-k);
			cur=k;
			continue;
		}
		if(k==-1){
			ans+=abs(cur-j);
			cur=k;
			continue;
		}
		if((abs(cur-k)<abs(cur-j))){
			ans+=abs(cur-k);
			cur=k;
		}else
		{
			ans+=abs(cur-j);
			cur=j;

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
//	parsed : 22-August-2021 18:03:54 IST