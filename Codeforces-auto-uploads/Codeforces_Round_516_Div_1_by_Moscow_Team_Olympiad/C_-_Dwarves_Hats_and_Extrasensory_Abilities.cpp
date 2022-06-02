/**
 *    author:  Aryan Agarwal
 *    created: 15.10.2021 19:31:03 IST
**/
#include <bits/stdc++.h>
using namespace std;

void solve()
{
	int n;
	cin>>n;

	string s;
	int mx=1e9;

	int org=0;
	char c0='b';

	cout<<"0 0"<<endl;
	cin>>s;
	c0=s[0];

	vector <int> v[2];
	v[0].push_back(0);

	for(int i=1;i<n;i++)
	{
		int m=(mx+org)/2;
		cout<<m<<" "<<m<<endl;
		cin>>s;

		if(s[0]==c0){
			v[0].push_back(m);
			org=m;
		}else{
			v[1].push_back(m);
			mx=m;
		}
	}

	sort(v[0].begin(),v[0].end());
	sort(v[1].begin(),v[1].end());

	int c=-1;

	if(!v[0].empty())c=2*v[0].back()+1;
	if(!v[1].empty())c=2*v[1][0]-1;

	mx=1e9;

	if(c>mx){
		cout<<c-mx<<" "<<mx<<" "<<mx<<" "<<c-mx<<"\n";
	}else{
		cout<<c<<" "<<0<<" "<<0<<" "<<c<<"\n";
	}

}

signed main()
{
	int _t = 1;
	// cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 15-October-2021 19:05:16 IST