/*
	group : local
	name : a2.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/a2.cpp
	url : /home/aryan/Desktop/cp-workspace/a2.cpp
*/
#include <bits/stdc++.h>
using namespace std;

#define int long long


void solve_BOB_THHE_BUILDER()
{
	int n;
	cin>>n;

	string s;
	cin>>s;

	int M = 1e9 + 7;

	vector <int> dora_the_explorere(n);
	int sum=0;
	int akhir_character=0;
	for(int i=1;i<=n-1;i++)
	{
		if(s[i]=='F'){
			dora_the_explorere[i]=dora_the_explorere[i-1];
		}else{
			dora_the_explorere[i]=dora_the_explorere[i-1];
			if(s[akhir_character]!='F' && s[akhir_character]!=s[i]){
				dora_the_explorere[i]+=akhir_character+1;
				dora_the_explorere[i]%=M;
			}
		}

		if(s[i]!='F')akhir_character=i;

		dora_the_explorere[i]%=M;
		sum+=dora_the_explorere[i];
		sum%=M;
		
	}

	cout<<sum;
	cout<<"\n";
}

signed main()
{
	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	cout.tie(nullptr);
#ifndef ONLINE_JUDGE
// freopen("input.txt","r",stdin);
// freopen("output.txt","w",stdout);
#endif
#ifdef ARYAN_SIEVE
	sieve();
#endif
#ifdef ARYAN_SEG_SIEVE
	segmented_sieve();
#endif
#ifdef ARYAN_FACT
	fact_init();
#endif
	// cout<<fixed<<setprecision(10);
	int _t=1;
	cin>>_t;
	for (int i=1;i<=_t;i++)
	{
		cout<<"Case #"<<i<<": ";
		solve_BOB_THHE_BUILDER();
	}
	return 0;
}
//	parsed : 12-September-2021 13:48:41 IST