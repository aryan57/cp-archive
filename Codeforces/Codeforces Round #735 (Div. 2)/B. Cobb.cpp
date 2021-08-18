/*
	group : Codeforces - Codeforces Round #735 (Div. 2)
	name : B. Cobb.cpp
	srcPath : /home/aryan/Desktop/cp-workspace/B_Cobb.cpp
	url : https://codeforces.com/contest/1554/problem/B
*/
/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 20:44:07 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n,k;
    // n=10;
    // k=7;
    cin>>n>>k;
    vector<int> a(n+1);
    for(int i=1;i<=n;i++)
    {
        // a[i]=rand()%(n+1);
        cin>>a[i];
        // cout<<a[i]<<" ";
    }

    // cout<<"\n";
    int ans=-1e18;

    int maxi=150;
    for(int i=n;i>=1;i--)
    {
        if(maxi--<=0)break;
        // int maxj=100;
        for(int j=i-1;j>=1;j--)
        {
            int t = i*j-k*(a[i]|a[j]);
            ans=max(ans,t);
            // cout<<t<<" ";
        }
        // cout<<"\n";
    }

    cout<<ans<<"\n";




}

signed main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(nullptr);
    int _t = 1;
    srand(8546524);
    cin>>_t;
    while(_t--)solve();
    return 0;
}
//	parsed : 29-July-2021 20:08:42 IST