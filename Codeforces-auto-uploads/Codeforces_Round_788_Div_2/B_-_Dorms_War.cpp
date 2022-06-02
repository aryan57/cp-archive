/**
 *    author:  Aryan Agarwal
 *    created: 06.05.2022 20:12:50 IST
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

	vector <bool> is_special(26);
	int k;
	cin>>k;
	while (k--)
	{
		char c;
		cin>>c;
		is_special[c-'a']=true;
	}
	
	int ans=0;
	stack<int> st;

	for(int i=0;i<n;i++){
		while (!st.empty() && is_special[s[i]-'a'])
		{
			ans=max(ans,i-st.top());
			st.pop();
		}
		st.push(i);
	}
	cout<<ans;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}