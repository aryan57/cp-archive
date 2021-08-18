/*
	group : CodeChef - July Cook-Off 2021 Division 2
	name : Chef In Infinite Plane.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/Chef_In_Infinite_Plane.cpp
	url : https://www.codechef.com/COOK131B/problems/CHFPLN
*/
/**
 *    author:  Aryan Agarwal
 *    created: 28.07.2021 22:49:49 IST
**/
#include <bits/stdc++.h>
using namespace std;

// #define int long long

void solve()
{
    int n;
    cin>>n;

    int mxn=1e5;
    vector<int> cnt(mxn+1);

    for(int i=0;i<n;i++){
        int x;
        cin>>x;
        cnt[x]++;
    }

    int ans=0;

    for(int i=2;i<=mxn;i++){
        ans+=min(cnt[i],i-1);
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
//	parsed : 28-July-2021 22:44:47 IST