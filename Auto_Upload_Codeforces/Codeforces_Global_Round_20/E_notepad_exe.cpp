/**
 *    author:  Aryan Agarwal
 *    created: 14.05.2022 11:11:53 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

int ask(int w){
	cout<<"? "<<w<<endl;
	fflush(stdout);
	int h;
	cin>>h;
	return h;
}

void solve()
{
	int n;
	cin>>n;

	int l=1;
	int r=2001*2001 + 1;

	int minTotal = r;

	while(l<=r){
		int m = (l+r)/2;
		int h = ask(m);

		if(h!=1){
			l=m+1;
		}else{
			minTotal=min(minTotal,m);
			r=m-1;
		}
	}
	int minArea = minTotal;
	for(int h=2;h<=n;h++){
		int remChars = minTotal - (h-1);
		int perLine = (remChars+h-1)/h;
		int newHeight = ask(perLine);
		if(newHeight)minArea=min(minArea,newHeight*perLine);
	}
	cout<<"! "<<minArea<<endl;
	fflush(stdout);
}

signed main()
{
	int _t=1;
	// cin>>_t;
	for (int i=1;i<=_t;i++){
		// cout<<"Case #"<<i<<": ";
		solve();
	}
	return 0;
}