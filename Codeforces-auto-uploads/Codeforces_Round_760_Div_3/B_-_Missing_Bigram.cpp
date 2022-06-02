/**
 *    author:  Aryan Agarwal
 *    created: 14.12.2021 20:35:05 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector <string> v(n-2);
	for(int i=0;i<n-2;i++){
		cin>>v[i];
	}

	string s="";
	s+=v[0][0];
	for(int i=0;i<n-2;i++){
		if(i==n-3){
			s+=v[i][1];
			s+=v[i][1];
			break;
		}
		if(v[i][1]==v[i+1][0]){
			s+=v[i][1];
		}else{
			s+=v[i][1];
			for(int j=i+1;j<n-2;j++){
				s+=v[j][0];
			}
			s+=v[n-3][1];
			break;
		}
	}

	assert(s.size()==n);
	cout<<s<<"\n";
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
//	parsed : 14-December-2021 20:35:02 IST