/**
 *    author:  Aryan Agarwal
 *    created: 29.07.2021 20:07:37 IST
**/
#include <bits/stdc++.h>
using namespace std;

#define int long long

void solve()
{
    int n;
    cin>>n;

    vector<int> a(n);
    int ans=0;

    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        if(i)
        {
            ans=max(ans,a[i]*a[i-1]);
        }
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
//	parsed : 29-July-2021 20:05:14 IST