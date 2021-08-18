/*
	group : Codeforces - Codeforces Round #698 (Div. 2)
	name : C. Nezzar and Symmetric Array.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Nezzar_and_Symmetric_Array.cpp
	url : https://codeforces.com/problemset/problem/1478/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 15.08.2021 12:19:11 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
	int n;
	cin>>n;
	vector<int> v(2*n);
	bool ok = true;
	for(int &x : v){
		cin>>x;
		if(x%2)ok=false;
		x/=2;
	}

	sort(v.begin(),v.end());

	vector<int> s(n),p(n);

	for(int i=1,ind=0;i<=2*n-1;i+=2,ind++){
		if(v[i]!=v[i-1]){
			ok=false;
			break;
		}
		s[ind]=v[i];
		p[ind]=v[i];
		if(ind>0){
			p[ind]=s[ind]-s[ind-1];
			if(p[ind]%ind){
				ok=false;
				break;
			}
			p[ind]/=ind;
			if(p[ind]==0){
				ok=false;
				break;
			}
		}
		
	}
	
	int sum=0,pre=0;

	for(int i=1;i<n;i++){
		pre+=p[i];
		sum+=pre;
	}

	if(p[0]<=sum || (p[0]-sum)%n){
		ok=false;
	}

	cout << ( ok ? "YES\n" : "NO\n");
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
//	parsed : 15-August-2021 12:02:01 IST