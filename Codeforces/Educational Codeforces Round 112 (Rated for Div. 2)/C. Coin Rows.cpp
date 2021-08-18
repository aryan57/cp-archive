/*
	group : Codeforces - Educational Codeforces Round 112 (Rated for Div. 2)
	name : C. Coin Rows.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/C_Coin_Rows.cpp
	url : https://codeforces.com/contest/1555/problem/C
*/
/**
 *    author:  Aryan Agarwal
 *    created: 30.07.2021 20:44:19 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<vector<int>> a(2,vector<int>(n));
    vector<int> suf(n+1);
    for(int i : {0,1}){
        for(int j=0;j<n;j++){
            cin>>a[i][j];
        }
    }

    for(int i=n-1;i>=0;i--){
        suf[i]+=a[0][i];
        suf[i]+=suf[i+1];
    }
    int inf=1e18;
    int ans=inf;
    int pre=0;
    for(int i=0;i<n;i++){

        int t=max(pre,suf[i+1]);

        ans=min(ans,t);

        pre+=a[1][i];
    }

    cout<<ans<<"\n";
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
//	parsed : 30-July-2021 20:39:04 IST