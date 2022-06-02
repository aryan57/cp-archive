/**
 *    author:  Aryan Agarwal
 *    created: 05.05.2022 20:43:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	int mx=0;

	vector <int> dest(26);
	iota(dest.begin(),dest.end(),0ll);

	for(int i=0;i<n;i++){
		if(s[i]-'a'>mx){
			int opreq=s[i]-'a'-mx;
			int opav=k;

			if(opreq<=opav){
				mx+=opreq;
				opav-=opreq;
				for(int j=0;j<=mx;j++)dest[j]=0;
				k=opav;
			}else{
				int to=s[i]-'a'-opav;
				for(int j=s[i]-'a';opav>=0;opav--,j--){
					dest[j]=to;
				}
				k=0;
				break;
			}
		}
	}
	
	for(int i=0;i<n;i++){
		char t='a';
		t+=dest[s[i]-'a'];
		cout<<t;
	}
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