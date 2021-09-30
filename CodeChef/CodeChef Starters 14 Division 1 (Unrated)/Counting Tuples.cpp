/*
	group : CodeChef - CodeChef Starters 14 Division 1 (Unrated)
	name : Counting Tuples.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Counting_Tuples.cpp
	url : https://www.codechef.com/START14A/problems/TUPCOUNT
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.09.2021 15:19:36 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long
const int mxn = 1e6;
vector<int> phi(mxn + 1);

void solve()
{
	int ans=0;

	int n;
	cin>>n;

	for(int i=1;i<=n;i++){
		int z=n/i;
		ans+=z*z*phi[i];
	}

	ans*=2;
	ans-=n*n;

	cout<<ans;
	cout<<"\n";
}

signed main()
{
	
    phi[0] = 0;
    phi[1] = 1;
    for (int i = 2; i <= mxn; i++)
        phi[i] = i;

    for (int i = 2; i <= mxn; i++) {
        if (phi[i] == i) {
            for (int j = i; j <= mxn; j += i)
                phi[j] -= phi[j] / i;
        }
    }

	ios_base::sync_with_stdio(false);
	cin.tie(nullptr);
	int _t = 1;
	cin>>_t;
	while(_t--)solve();
	return 0;
}