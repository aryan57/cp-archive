/**
 *    author:  Aryan Agarwal
 *    created: 17.08.2021 15:45:54 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	string s;
	cin>>s;
	int ans=0;

	s+='#';
	deque<int> t;
	for(int i=0;i<n;i++){
		if(s[i]!=s[i+1]){
			t.push_back(s[i]-'0');
		}else{

			int cnt=2;
			int j=i+2;
			while(j<n){
				if(s[j]!=s[i])break;
				cnt++;
				j++;
			}

			if(cnt<=t.size()+1){
				int k=cnt-1;
				while(k--){
					t.pop_front();
					ans++;
				}
				t.push_back(s[i]-'0');
			}else{
				while(!t.empty()){
					t.pop_front();
					ans++;
				}
				ans++;
			}

			i=j-1;

		}
	}

	ans+=(t.size()+1)/2;

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
//	parsed : 17-August-2021 14:51:23 IST