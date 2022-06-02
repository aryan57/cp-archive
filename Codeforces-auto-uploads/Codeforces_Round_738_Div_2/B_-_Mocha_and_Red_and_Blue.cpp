/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 20:10:05 IST
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
	
	bool ok = false;
	for(int i=0;i<n;i++){

		if(s[i]=='R'){
			ok=true;
			char z='B';
			for(int j=i-1;j>=0;j--){
				if(s[j]!='?')break;
				s[j]=z;
				z=z^('R')^('B');
			}

		}
		else if(s[i]=='B'){
			char z='R';
			ok=true;
			for(int j=i-1;j>=0;j--){
				if(s[j]!='?')break;
				s[j]=z;
				z=z^('R')^('B');
			}

		}

	}

	if(!ok){
		char z='R';
		for(int i=0;i<n;i++){
			s[i]=z;
			z=z^('R')^('B');
		}
	}

	if(s[n-1]=='?'){

		for(int i=0;i<n;i++){
			if(s[i]=='?'){
				assert(i>0);
				char z=s[i-1];
				ok=true;
				for(int j=i;j<n;j++){
					z=z^('R')^('B');
					s[j]=z;
				}

				break;
			}
		}

	}

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
//	parsed : 15-August-2021 20:08:06 IST