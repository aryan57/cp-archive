/*
	group : CodeChef - August Cook-Off 2021 Division 2
	name : Clear the Array.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Clear_the_Array.cpp
	url : https://www.codechef.com/COOK132B/problems/CLEARARR
*/
/**
 *    author:  Aryan Agarwal
 *    created: 22.08.2021 22:08:24 IST
**/
#include <bits/stdc++.h>
using namespace std;
#include <sys/resource.h>

#define int long long

void solve()
{
	int n,k,x;
	cin>>n>>k>>x;

	vector<int> v(n);
	int ans=0;
	for(int &x : v){
		cin>>x;
		ans+=x;
	}

	sort(v.begin(),v.end(),greater<int> ());

	k*=2;
	for(int i=1;i<n;i+=2){
		if(k==0)break;
		if(v[i]+v[i-1]>x){
			// cerr<<ans<<" "<<i<<" "<<k<<"%\n";
			k-=2;
			ans-=(v[i]+v[i-1]);
			ans+=x;
			// cerr<<ans<<" "<<i<<" "<<k<<"%\n";
		}else{
			break;
		}
	}

	cout<<ans<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);

	rlimit R;
	getrlimit(RLIMIT_STACK, &R);
	R.rlim_cur = R.rlim_max;
	setrlimit(RLIMIT_STACK, &R);

	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}
//	parsed : 22-August-2021 21:57:31 IST